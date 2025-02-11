#ifndef ARCHIVO_MIF_H
#define ARCHIVO_MIF_H
#include "archivo.h"
#include "imagen.h"
#include <fstream>
#include <iostream>

class Archivo_Mif:public archivo{
public:
    bool cargar(string nombre,Imagen &imagen);
    bool guardar(string nombre,Imagen &imagen);
};

#endif // ARCHIVO_MIF_H
