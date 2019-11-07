#include "funcs.h"

vector<string> vecQuelee(string s){
    ifstream file;
    file.open(s);
    vector<string> v1;
    if(!file.is_open()){
        cout << "No se ha podido abrir el archivo ";
    }
    else{
        string line;
        string myStr;
        while(getline(file,line)){
            stringstream ss(line);
            getline(ss,myStr);
            v1.push_back(myStr);
        }
    }
    return v1;
}

void generarArchivo(vector<string> v1){
    ofstream file2;
    string path2 = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/results.txt";
    file2.open(path2);
    string num;
    int mayor = 0;
    int num1;
    char empty = ' ';
    int sum;
    int menor;
    string alias;
    vector<int> bids;
    vector<string> low;
    unordered_map<string,int> m1;

    for(auto it = v1.begin(); it != v1.end();it++){
        if(it == v1.begin() && isupper((*it)[0])){
            file2 << *it;
        }
        if(isupper((*it)[0]) && it != v1.begin()){
            sum = 0;
            menor = 99999;
            for(auto it4 : bids){
                if(it4 > mayor){
                    mayor = it4;
                }
                if(it4 < menor){
                    menor = it4;
                }
                sum += it4;
            }
            double size = bids.size();
            double promedio = sum / size;
            file2 << ',' << mayor << ',' << promedio << ',' << menor;
            file2 << endl << *it;
            bids.clear();
        }
        if(islower((*it)[0])){
            low.push_back(*it);
            alias = "";
            auto it2 = (*it).begin();
            auto itr = find((*it).begin(),(*it).end(),empty);
            while(it2 != itr){
                alias += *it2;
                it2++;
            }
            itr++;
            num = " ";
            while(itr != (*it).end()){
                num += *itr;
                itr++;
            }
            num1 = stoi(num);
            bids.push_back(num1);
            m1.insert(pair<string,int>(alias,num1));
        }
    }

    for(auto it : m1){
        cout << it.first << " " << it.second;
        cout <<endl;
    }
}