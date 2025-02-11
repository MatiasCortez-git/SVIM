#ifndef PROCESADOR_H
#define PROCESADOR_H
#include <imagen.h>


class Procesador
{
public:
   virtual void Procesar(Imagen &Ima)=0;
   virtual ~Procesador(){}
};

#endif // PROCESADOR_H
