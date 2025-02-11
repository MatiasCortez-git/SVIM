#include "metadatos.h"

void Metadatos::Insetar(string clave,string valor)
{
   m[clave]=valor;
}
string Metadatos::ver_valor(string codigo)
{
    string aux = "no se encontro";
    if(m.find(codigo) != m.end())
        aux=m[codigo];
    return aux;
}
vector<string> Metadatos::get_metadatos(){
    map<string,string>::iterator p,q;
    vector<string>claves;
    p=m.begin();
    q=m.end();
    while(p!=q)
    {
       claves.push_back((*p).first);
       p++;
    }

    return claves;
}

