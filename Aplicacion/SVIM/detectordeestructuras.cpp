#include "detectordeestructuras.h"

DetectorDeEstructuras::DetectorDeEstructuras(unsigned x, unsigned y){
    coor_x=x;
    coor_y=y;
    verde.set_verde(1.0);

}

void DetectorDeEstructuras::Procesar(Imagen &Ima){
    imi=Ima;
    imf.set_dimension(Ima.get_cantidad_px(),Ima.get_cantidad_py());
    imf.set_alto(Ima.get_alto());
    imf.set_ancho(Ima.get_ancho());
    base=Ima(coor_x,coor_y);
    AlgoritmoDelPintor(coor_x,coor_y);
    Ima=imf;
}

void DetectorDeEstructuras::AlgoritmoDelPintor(int x, int y)
{
    if((x>=0)&&(x<(int)imi.get_cantidad_px()))
        if((y>=0)&&(y<(int)imi.get_cantidad_py()))
            if(imf(x,y)==negro)
                if(imi(x,y)==base)
                {
                    imf.set_pixel(x,y,verde);
                    AlgoritmoDelPintor(x-1,y+1);
                    AlgoritmoDelPintor(x,y+1);
                    AlgoritmoDelPintor(x+1,y+1);
                    AlgoritmoDelPintor(x-1,y);
                    AlgoritmoDelPintor(x+1,y);
                    AlgoritmoDelPintor(x-1,y-1);
                    AlgoritmoDelPintor(x,y-1);
                    AlgoritmoDelPintor(x+1,y-1);
                }
}
