#ifndef SISTEMA_H
#define SISTEMA_H
#include <QApplication>
#include <QObject>
#include <QTimer>
#include "imagen.h"
#include "archivo_mif.h"
#include "graficador.h"
#include "filtrodecolor.h"
#include "detectordeestructuras.h"
#include "oscuredor.h"
using namespace std;
class Sistema: public QObject
{
    Q_OBJECT
    Imagen ima;
    QApplication a;
    Graficador g;
    QTimer cronometro;
    vector<string>archivos;
    unsigned cont;
public:
    Sistema(int argc, char *argv[]);
    unsigned MostrarPixelX();
    unsigned MostrarPixelY();
    unsigned MostrarAncho();
    unsigned MostrarAlto();
    Imagen MostrarImagen();
    string MostrarUnidad();
    Metadatos MostrarMetadatos();
    string MostrarValor(string codigo);
    void ModificarDimension(unsigned x1,unsigned y1);
    void ModificarAncho(unsigned a);
    void ModificarAlto(unsigned a1);
    void ModificarUnidad(string u);
    void ModificarMetadato(string c, string v);
    bool ModificarPixel(unsigned x1,unsigned y1, float r1, float g1, float b1);
    bool Cargar_Imagen(string nombre);
    bool Guardar_Imagen(string nombre);
    void VisualizarImagen();
    void AplicarFiltro(float r,float g, float b);
    void AplicarDetector(unsigned x,unsigned y);
    bool temporizar(string clave,string valor,string nombre);
    void osc();
private slots:

   void cambiar_imagen();
};

#endif // SISTEMA_H
