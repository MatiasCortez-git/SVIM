#ifndef OSCUREDOR_H
#define OSCUREDOR_H
#include <procesador.h>

class oscuredor : public Procesador
{
public:
    oscuredor();
    void Procesar(Imagen &Ima);
    ~oscuredor(){}
};

#endif // OSCUREDOR_H
