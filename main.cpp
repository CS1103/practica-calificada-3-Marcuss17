#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct participante{
	string nombre;
	int bid;
bool operator<(const participante& p2) const{
	if(bid > p2.bid && nombre != p2.nombre) return true;
	else if(bid == p2.bid && nombre != p2.nombre) return true;
}
};


int main(){
	ifstream file;
	file.open("/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/bid_example.txt");
	set <participante> s1;
	string key;
	char empty = ' ';
	string alias;
	string snum;
	string smayor;
	string smenor;
	string sprom;
	int num;
	vector <string> v1;
	vector <int> v2;
	int mayor;
	int menor;
	float prom;
	bool isIn;
	float sum;
	map <string,set<participante>> map1;
	if(!file.is_open())
		cout << "Error abriendo el archivo";
	else{
		string line;
		while(getline(file,line)){
			string myStr;
			stringstream ss(line);
			getline(ss,myStr);
			v1.push_back(myStr);
		}		
	}
	file.close();
	for(auto it = v1.begin(); it != v1.end(); it++){
		if(it == v1.begin() && isupper((*it)[0])){
			key = *it;
		}
		if((it != v1.begin() && isupper((*it)[0])) || (it == v1.end()-1)){
			sum = 0;
			mayor = 0;
			menor = 99999;
			for(auto it : v2){
				sum += it;
				if(it > mayor)
					mayor = it;
				if(it < menor)
					menor = it;
			}
			prom = sum/v2.size();
			smayor = to_string(mayor);
			smenor = to_string(menor);
			sprom = to_string(prom);
			key += ',';
			key += smayor;
			key += ',';
			key += sprom;
			key += ',';
			key += smenor;
			map1.insert(pair<string,set<participante>>(key,s1));
			key = *it;
			s1.clear();
			v2.clear();
			
		}

		else if(islower((*it)[0])){
			auto it2 = find((*it).begin(), (*it).end(), empty);
			auto it3 = (*it).begin();
			auto it4 = (*it).end();
			snum ="";
			alias ="";
			it2++;
			isIn = 0;
			while(it3 != it2){
				alias += (*it3);
				it3++;
			}
			while(it2 != it4){
				snum += *it2;
				it2++;
			}
			num = stoi(snum);
			participante p1;
			p1.nombre = alias;
			p1.bid = num;
			if(s1.size() > 0){
				for(auto it : s1)
					if(alias == it.nombre)
						isIn = 1;	
			}
			if(s1.size() == 0 || !(isIn)){
				s1.insert(p1);
			}
			if(isIn){
				for(auto it : s1)
					if(alias == it.nombre){
						it.nombre = alias;
						it.bid = num;
					}
			}
			v2.push_back(num);
		}
	}
	
	auto it5 = map1.end();
	it5--;	
	/*for(auto it = map1.begin(); it != map1.end(); it++){
		auto &s2 = (*it).second;
		auto it2 = it;
		if(it != it5){
			it2++;
			for(;it2 != map1.end(); it2++){
				auto& s3 = (*it2).second;
				for(auto it3 = s2.begin(); it3 != s2.end(); it3++)
					for(auto it4 = s3.begin(); it4 != s3.end(); it4++)
						if((*it3).nombre == (*it4).nombre)
							s2.erase(it3);
			}
		}
	}*/
	vector<string> toEliminate;
	for(auto it = map1.begin(); it != map1.end(); it++){
		auto &s2 = (*it).second;
		auto it2 = it;
		if(it != it5){
			it2++;
			for(;it2 != map1.end(); it2++){
				auto& s3 = (*it2).second;
				for(auto it3 = s2.begin(); it3 != s2.end(); it3++)
					for(auto it4 = s3.begin(); it4 != s3.end(); it4++)
						if((*it3).nombre == (*it4).nombre)
							toEliminate.push_back((*it3).nombre);
			}
		}
	}
	reverse(toEliminate.begin(),toEliminate.end());	
	for(auto it : toEliminate){cout << it;}
	cout << endl;
	for(auto& it : map1){
		auto& s2 = it.second;
		for(auto it1 : s2){
			for(const auto& it3 : toEliminate){
				if(it1.nombre == it3){
					cout << it1.nombre ;
					s2.erase(it1);
				} 
			}
		}
	}
	
	ofstream file2;
	file2.open("/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/results2.txt");
	if(!file2.is_open()){cout << "Error al abrir el archivo!";}
	else{
		for(auto it : map1){
			file2 << it.first << endl;
			auto s2 = it.second;
			for(auto it2 : s2){
				file2 << it2.nombre << ':' << it2.bid << endl;
			}
		}
	}
	file2.close();	

	for(auto it : map1){
		cout << it.first << endl;
		auto s2 = it.second;
		for(auto it2 : s2){
			cout << it2.nombre << ':' << it2.bid << endl;}
	}
	
	
return 0;
}
