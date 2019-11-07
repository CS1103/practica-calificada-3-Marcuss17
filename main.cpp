#include "funcs.h"

using namespace std;

struct str{
    string product;
    vector<string> bids;
};

int main() {
    string path = "/home/eduardo/Desktop/Utec/Poo2/practica-calificada-3-Marcuss17/bid_example.txt";
    auto v1 = vecQuelee(path);
    /*ifstream file;
    file.open(path);
    vector<str> strs;
    auto it = strs.begin();
    if(!file.is_open()){
        cout << "No se ha podido abrir el archivo ";
    }
    else{
        string line;
        string myStr;
        while(getline(file,line)){
            stringstream ss(line);
            getline(ss,myStr);
            if(isupper((myStr)[0])){
                str s;
                s.product = myStr;
                strs.push_back(s);
            }
            else{

            }
            v1.push_back(myStr);
        }
    }*/
    generarArchivo(v1);
    return 0;
}