#ifndef DETECTORDEESTRUCTURAS_H
#define DETECTORDEESTRUCTURAS_H
#include <procesador.h>


class DetectorDeEstructuras : public Procesador
{
private:
    unsigned coor_x;
    unsigned coor_y;
    Imagen imi,imf;
    Pixel base,negro,verde;

public:
    DetectorDeEstructuras(unsigned x,unsigned y);
    void Procesar(Imagen &Ima);
    void AlgoritmoDelPintor(int x, int y);
};

#endif // DETECTORDEESTRUCTURAS_H
