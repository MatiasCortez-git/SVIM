#include "sistema.h"
using namespace std;
Sistema::Sistema(int argc, char *argv[]):a(argc,argv)
{
   connect(&cronometro,SIGNAL(timeout()),SLOT(cambiar_imagen()));

}

unsigned Sistema::MostrarPixelX()
{
 return ima.get_cantidad_px();
}

unsigned Sistema::MostrarPixelY()
{
 return ima.get_cantidad_py();
}

unsigned Sistema::MostrarAncho()
{
     return ima.get_ancho();
}

unsigned Sistema::MostrarAlto()
{
     return ima.get_alto();
}

Imagen Sistema::MostrarImagen(){
    return ima;}

string Sistema::MostrarUnidad()
{
     return ima.get_unidad();
}

Metadatos Sistema::MostrarMetadatos()
{
     return ima.get_metadato();
}

string Sistema::MostrarValor(string codigo){
  return (ima.get_metadato()).ver_valor(codigo);
}

void Sistema::ModificarDimension(unsigned x1,unsigned y1){
    ima.set_dimension(x1,y1);                            }

void Sistema::ModificarAncho(unsigned a){
    ima.set_ancho(a);                   }

void Sistema::ModificarAlto(unsigned a1){
    ima.set_alto(a1);                   }

void Sistema::ModificarUnidad(string u){
    ima.set_unidad(u);                 }

bool Sistema::ModificarPixel(unsigned x1, unsigned y1, float r1, float g1, float b1){
    Pixel p;
    p.set_rojo(r1);
    p.set_verde(g1);
    p.set_azul(b1);
    return ima.set_pixel(x1,y1,p);
}

void Sistema::ModificarMetadato(string c, string v){
    ima.set_metadato(c,v);
}

bool Sistema::Cargar_Imagen(string nombre){
    Archivo_Mif archi;
    return archi.cargar(nombre,ima);
}

bool Sistema::Guardar_Imagen(string nombre){
    Archivo_Mif archi;
    return archi.guardar(nombre,ima);
}

void Sistema::VisualizarImagen(){
    g.CargarImagen(ima);
    g.resize(300,300);
    g.show();
    a.exec();
}

void Sistema::AplicarFiltro(float r, float g, float b){
    Pixel p;
    p.set_rojo(r);
    p.set_verde(g);
    p.set_azul(b);
    FiltroDeColor f(p);
    f.Procesar(ima);
}

void Sistema::AplicarDetector(unsigned x, unsigned y){
    DetectorDeEstructuras d(x,y);
    d.Procesar(ima);

}
bool Sistema::temporizar(string clave, string valor, string nombre)
{
    archivos.clear();
    bool condicion=false;
    ifstream archi2(nombre.c_str());
    Archivo_Mif archi;
    string s;
     while(archi2>>s)
    {
        archi.cargar(s,ima);
        if(valor==(ima.get_metadato()).ver_valor(clave))
        {
            archivos.push_back(s);
        }
    }

    if(archivos.size()!=0)
    {
        cont=0;
        archi.cargar(archivos[cont],ima);
        cont=1;
        g.CargarImagen(ima);
        g.resize(300,300);
        g.show();
        cronometro.start(3000);
        a.exec();
        condicion=true;
    }
    return condicion;
}
void Sistema::cambiar_imagen()
{
    Archivo_Mif archi;
    if(cont==archivos.size()-1)
    {
        archi.cargar(archivos[cont],ima);
        g.CargarImagen(ima);
        g.update();
        //cronometro.stop();
        cont=0;

    }
    else
    {
        archi.cargar(archivos[cont],ima);
        g.CargarImagen(ima);
        g.update();
        cont++;
    }
}
void Sistema::osc()
{
    oscuredor o;
    o.Procesar(ima);
}
