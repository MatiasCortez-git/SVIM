#ifndef IMAGEN_H
#define IMAGEN_H
#include <vector>
#include <string>
#include "pixel.h"
#include "metadatos.h"
using namespace  std;

class Imagen
{private:
    vector< vector< Pixel > > matriz;
    unsigned cantidad_px;
    unsigned cantidad_py;
    float ancho_imagen;
    float alto_imagen;
    string unidad;
    Metadatos m;

public:
    Imagen();
    bool set_pixel(unsigned X, unsigned Y, Pixel aux);
    void set_ancho(float ancho);
    void set_alto(float alto);
    void set_unidad(string u);
    void set_dimension(unsigned x,unsigned y);
    void  set_metadato(string clave,string valor);
    void CargarMetadato(Metadatos m2);
    Pixel operator()(unsigned X, unsigned Y);
    unsigned get_cantidad_px();
    unsigned get_cantidad_py();
    float get_ancho();
    float get_alto();
    string get_unidad ();
    Metadatos  get_metadato();
};

#endif // IMAGEN_H
