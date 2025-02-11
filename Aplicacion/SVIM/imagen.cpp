#include "imagen.h"

Imagen::Imagen(){
    cantidad_px=0;
    cantidad_py=0;
    ancho_imagen=0;
    alto_imagen=0;
}

bool Imagen::set_pixel(unsigned X, unsigned Y, Pixel aux){
    bool condicion=false;
    if((X<cantidad_px)&&(Y<cantidad_py)){
        matriz[Y][X]=aux;
        condicion=true;}
    return condicion;}

void Imagen::set_alto( float alto){
    alto_imagen=alto;}

void Imagen::set_ancho(float ancho){
    ancho_imagen=ancho;}

void Imagen::set_unidad(string u){
    unidad=u;}

void Imagen::set_dimension (unsigned x, unsigned y){
    cantidad_px=x;
    cantidad_py=y;
    matriz.resize(cantidad_py);
    for(unsigned i=0;i<cantidad_py;i++)
        matriz[i].resize(cantidad_px); }

void Imagen::set_metadato(string clave, string valor)//-------------------------------------------------
{
    m.Insetar(clave,valor);
}

void Imagen::CargarMetadato(Metadatos m2){
    m=m2;
}

unsigned Imagen::get_cantidad_px(){
    return cantidad_px;}

unsigned Imagen::get_cantidad_py(){
    return cantidad_py;}

float Imagen::get_ancho(){
    return ancho_imagen;}

float Imagen::get_alto(){
    return alto_imagen;}

string Imagen::get_unidad(){
    return unidad;}

Pixel Imagen::operator ()(unsigned X, unsigned Y){

    return matriz[Y][X];}
Metadatos Imagen::get_metadato()//----------------------------------------------------
{
    return m;
}

