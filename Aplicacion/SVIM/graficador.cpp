#include "graficador.h"

Graficador::Graficador(QWidget * parent) : QOpenGLWidget (parent)
{

}

void Graficador::initializeGL()
{
   initializeOpenGLFunctions();
   glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void Graficador::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,0,h,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Graficador::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    float relacion_w,relacion_h;//relacion de aspecto
    relacion_w=((float)width())/(float)Ima.get_cantidad_px();
    relacion_h=((float)height())/(float)Ima.get_cantidad_py();
    desplazarX=0.0f;
    desplazarY=0.0f;
    if(relacion_w<relacion_h){
        escala=relacion_w;
        desplazarY=(height()-escala*Ima.get_cantidad_py())*0.5f;
    }
    else{
        escala=relacion_h;
        desplazarX=(width()-escala*Ima.get_cantidad_px())*0.5f;
    }

    GraficarImagen();

}


void Graficador::GraficarImagen()
{
    glPushMatrix();
    glTranslatef(desplazarX,desplazarY,0.0f);
    glScalef(escala,escala,1.0f);
    glBegin(GL_QUADS);
    for(unsigned i=0;i<Ima.get_cantidad_py();i++){
        for(unsigned j=0;j<Ima.get_cantidad_px();j++){
            glColor3f(Ima(j,i).get_rojo(),Ima(j,i).get_verde(),Ima(j,i).get_azul());
            glVertex3f(j,Ima.get_cantidad_py()-i,0);
            glVertex3f(j,Ima.get_cantidad_py()-(i+1),0);
            glVertex3f(j+1,Ima.get_cantidad_py()-(i+1),0);
            glVertex3f(j+1,Ima.get_cantidad_py()-i,0);
        }}
    glEnd();
    glPopMatrix();}

void Graficador::CargarImagen(Imagen I){
    Ima=I;
}
