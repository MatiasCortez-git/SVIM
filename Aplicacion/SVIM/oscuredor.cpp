#include "oscuredor.h"

oscuredor::oscuredor()
{

}

void oscuredor::Procesar(Imagen &Ima){
    Pixel aux;
    for(unsigned i=0;i<Ima.get_cantidad_py();i++)
          for(unsigned j=0;j<Ima.get_cantidad_px();j++)
          {
              aux.set_rojo(Ima(j,i).get_rojo()/2);
              aux.set_verde(Ima(j,i).get_verde()/2);
              aux.set_azul(Ima(j,i).get_azul()/2);
              Ima.set_pixel(j,i,aux);

          }
}
