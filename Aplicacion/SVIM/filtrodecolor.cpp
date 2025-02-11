#include "filtrodecolor.h"

FiltroDeColor::FiltroDeColor(Pixel aux){
    base=aux;
}

void FiltroDeColor::Procesar(Imagen &Ima){
    Pixel aux;
    for(unsigned i=0;i<Ima.get_cantidad_py();i++)
          for(unsigned j=0;j<Ima.get_cantidad_px();j++){
              if(!(Ima(j,i)==base))
                {
                  aux.set_rojo(Ima(j,i).intensidad());
                  aux.set_verde(Ima(j,i).intensidad());
                  aux.set_azul(Ima(j,i).intensidad());
                  Ima.set_pixel(j,i,aux);
     }
}
}
