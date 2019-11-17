#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using std::ifstream; using std::ofstream; using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::stringstream; using std::map; using std::to_string;

int main(){
	ifstream file;
	string ruta= "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/bid_example.txt";
	file.open(ruta);
	vector<string> v1;
	string key;
	string alias;
	string sbid;
	int nbid;
	map<string,map<string,int> > m1;
	map<string,int> m2;
	vector<string> toEliminate;
	vector<int> numbers;
	string smayor,smenor,sprom;
	int mayor;
	int menor;
	float prom;
	float sum;
	if(!file.is_open()){cout << "No se pudo abrir el archivo!";}
	else{	
		string fila;
		string myStr;
		while(getline(file,fila)){
			stringstream ss(fila);
			getline(ss,myStr);
			v1.push_back(myStr);
		}
	}
	file.close();
	
	for(auto it = v1.begin(); it != v1.end(); it++){
		if(isupper((*it)[0])  && it == v1.begin()){
			key = *it;
		}
		else if((it != v1.begin() && isupper((*it)[0])) || it == v1.end()-1){
			sum = 0;
			mayor = 0;
			menor = 99999;
			for(auto it : numbers){
				sum+=it;
				if(it > mayor)
					mayor = it;
				if(it < menor)
					menor = it;
			} 
			prom = sum/numbers.size();
			smayor = to_string(mayor);
			smenor = to_string(menor);
			sprom = to_string(prom);
			key += ',';
			key += smayor;
			key += ',';
			key += sprom;
			key += ',';
			key += smenor;
			m1[key] = m2;
			m2.clear();
			numbers.clear();
			key = *it;
				
		}
		else if(islower((*it)[0])){
			string current = *it;
			alias ="";
			sbid ="";
			auto it2 = find(current.begin(),current.end(),' ');
			it2++;
			auto it3 = current.begin();
			while(it3 != it2){
				alias+=*it3;
				it3++;
			}
			while(it2 != current.end()){
				sbid += *it2;
				it2++;
			}		
			nbid = stoi(sbid);
			numbers.push_back(nbid);
			m2[alias] = nbid;
		}
	}
	
	for(auto it = m1.begin(); it != m1.end(); it++){
		auto it2 = it;
		auto m2 = (*it).second;
		it2++;
		for(;it2 != m1.end(); it2++){
			auto m3 = (*it2).second;
			for(auto it3 : m2){
				for(auto it4 : m3){
					if(it3.first == it4.first){
						toEliminate.push_back(it3.first);
					}
				}
			}
		}
	}

	for(auto& it : m1){
		auto& m2 = it.second;
		for(auto it2 : m2){
			for(const auto& it3: toEliminate){
				if(it2.first == it3){
					m2.erase(it2.first);
				}
			}
		}
	}

	ofstream file2;
	string ruta2= "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/finalResult.txt";
	file2.open(ruta2);
	if(!file2.is_open()){cout << "No se pudo abrir el archivo";}
	else{
		for(auto it : m1){
			file2 << it.first << endl;
			auto m3 = it.second;
			for(auto it2 : m3)
				file2 << it2.first << ':' << it2.second << endl;	
		}
	}	
	
	file2.close();

	for(auto it : m1){
		cout << it.first << endl;
		auto m3 = it.second;
		for(auto it2 : m3)
			cout << it2.first << ':' << it2.second << endl; 
	}	
return 0;
}
