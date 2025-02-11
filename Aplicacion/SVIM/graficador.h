#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "imagen.h"
#undef byte



class Graficador : public QOpenGLWidget, protected QOpenGLFunctions
{
private:
    float escala;// para mantener las proporciones para cualquier tamaño de ventana
    float desplazarX;//para desplazar la imagen al centro
    float desplazarY;
    Imagen Ima;


public:
    Graficador(QWidget * parent=0);
    void CargarImagen(Imagen I);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void GraficarImagen();
};

#endif // GRAFICADOR_H
