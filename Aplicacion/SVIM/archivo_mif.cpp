#include "archivo_mif.h"

bool Archivo_Mif::cargar(string nombre,Imagen& imagen){

    ifstream archi;
    archi.open(nombre.c_str());
    int n;
    char punto;
    unsigned ancho,alto;
    unsigned short aux1,aux2,aux3;
    string unidad;
    string cadena;
    float x,y,max=65535.0;
    Pixel pixel;
    bool condicion=archi.good();

    if(condicion)
    {
    archi>>x>>punto>>y>>punto>>ancho>>punto>>alto>>punto>>unidad;
    imagen.set_ancho(ancho);
    imagen.set_alto(alto);
    imagen.set_dimension(x,y);
    imagen.set_unidad(unidad);
    archi.ignore();
    getline(archi,cadena);
    unsigned pos=0;
    unsigned d;
    size_t c;
    string cad1,cad2;
    Metadatos m;
    while(pos<cadena.size())
    {
        c=cadena.find(";",pos);
        if(c!=string::npos){
            d=cadena.find(":",pos);
            cad1=cadena.substr(pos,d-pos);
            cad2=cadena.substr(d+1,c-d-1);
            m.Insetar(cad1,cad2);
            pos=c+1;
            }
        else{
            d=cadena.find(":",pos);
            cad1=cadena.substr(pos,d-pos);
            cad2=cadena.substr(d+1,cadena.size());
            m.Insetar(cad1,cad2);
            pos=cadena.size();
            }
   }
   imagen.CargarMetadato(m);
    archi.close();
 //parte binaria
    archi.open(nombre.c_str(),ios::in|ios::binary);
    n=(6*x*y);
    archi.seekg(-n,ios::end);
    for(unsigned i=0;i<y;i++)
        for(unsigned j=0;j<x;j++)
            {
            archi.read((char*)&aux1,sizeof(unsigned short));
            archi.read((char*)&aux2,sizeof(unsigned short));
            archi.read((char*)&aux3,sizeof(unsigned short));
            pixel.set_rojo(float(aux1/max));
            pixel.set_verde(float(aux2/max));
            pixel.set_azul(float(aux3/max));
            imagen.set_pixel(j,i,pixel);

             }
    }
    archi.close();
    return condicion;
    }
bool Archivo_Mif::guardar(string nombre, Imagen &imagen){
    ofstream archi;
    archi.open(nombre.c_str());
    unsigned short aux1,aux2,aux3;
    unsigned max=65535;
    Metadatos datos;
    datos=imagen.get_metadato();
    vector<string>claves;
    claves=datos.get_metadatos();
    bool condicion=archi.bad();
    if (!condicion)
    {
    archi<<imagen.get_cantidad_px()<<";"<<imagen.get_cantidad_py()<<";"<<imagen.get_ancho();
    archi<<";"<<imagen.get_alto()<<";"<<imagen.get_unidad()<<endl;
    for(unsigned i=0;i<claves.size();i++)
    {
        if(i==0)
            archi<<claves[i]<<":"<<datos.ver_valor(claves[i]);
        else
        {
         archi<<";"<<claves[i]<<":"<<datos.ver_valor(claves[i]);
        }
    }

    archi<<endl;
    archi.close();
    //parte binaria
    archi.open(nombre.c_str(),ios::app|ios::binary);
    for(unsigned i=0;i<imagen.get_cantidad_py();i++)
        for(unsigned j=0;j<imagen.get_cantidad_px();j++)
            {
            aux1=imagen(j,i).get_rojo()*max;
            archi.write((char*)&aux1,sizeof(unsigned short));
            aux2=imagen(j,i).get_verde()*max;
            archi.write((char*)&aux2,sizeof(unsigned short));
            aux3=imagen(j,i).get_azul()*max;
            archi.write((char*)&aux3,sizeof(unsigned short));
             }
    condicion=true;
    }
    archi.close();
    return condicion;}
