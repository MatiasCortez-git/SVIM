#ifndef METADATOS_H
#define METADATOS_H
#include <map>
#include <string>
#include <vector>
using namespace std;

class Metadatos
{
private:
    map<string,string> m;

public:
    void Insetar(string clave,string valor);
    string ver_valor(string codigo);
    vector<string>get_metadatos();
};



#endif // METADATOS_H
