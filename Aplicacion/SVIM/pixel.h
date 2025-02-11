#ifndef PIXEL_H
#define PIXEL_H
#include <math.h>

class Pixel
{private:
    float Rojo;
    float Verde;
    float Azul;
public:
    Pixel();
    void set_rojo (float r);
    void set_verde (float v);
    void set_azul (float a);
    float get_rojo ();
    float get_verde();
    float get_azul ();
    float intensidad();
    Pixel operator+(Pixel p2);
    Pixel operator/( float n);
    bool operator==(Pixel p2);


};


#endif // PIXEL_H
