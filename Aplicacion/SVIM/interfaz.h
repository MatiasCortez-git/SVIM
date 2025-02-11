#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <string>
#include "sistema.h"

class Interfaz
{
public:
    void menu(int argc, char *argv[]);
};
ostream& operator<<(ostream& salida,Imagen im);
#endif
//INTERFAZ_H
//---------------------------------------------------------------------

