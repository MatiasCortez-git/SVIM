#ifndef FILTRODECOLOR_H
#define FILTRODECOLOR_H
#include <procesador.h>
using namespace std;

class FiltroDeColor : public Procesador
{
    private:
          Pixel base;
    public:
          FiltroDeColor(Pixel aux);
          void Procesar(Imagen &Ima);
          ~FiltroDeColor(){}
};
#endif
