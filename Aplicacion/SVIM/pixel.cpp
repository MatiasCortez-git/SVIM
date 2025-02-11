#include "pixel.h"

Pixel::Pixel(){
    Rojo=0.0;
    Verde=0.0;
    Azul=0.0;}

void Pixel::set_rojo (float r){
    if(r<0)
        r=0;
    if(r>1)
        r=1;

    Rojo=r;}

void Pixel::set_verde (float v){
    if(v<0)
        v=0;
    if(v>1)
        v=1;

    Verde=v;}

void Pixel::set_azul (float a){
    if(a<0)
        a=0;
    if(a>1)
        a=1;
    Azul=a;}

float Pixel::get_rojo(){
    return Rojo;}

float Pixel::get_verde (){
    return Verde;}

float Pixel::get_azul(){
    return Azul;}

float Pixel::intensidad (){
    float i;
    i= (Rojo+Verde+Azul)/3.0;
    return i;             }

Pixel Pixel::operator+(Pixel p2){ //p3=p1+p2
    Pixel p3;
    p3.set_rojo(p2.get_rojo()+ Rojo );
    p3.set_verde(p2.get_verde()+ Verde );
    p3.set_azul(p2.get_azul()+ Azul );
    return p3;                   }

Pixel Pixel::operator/(float n){//p2=p1/n
   Pixel p2;
   if(n>0){
      p2.set_rojo(Rojo/n);
      p2.set_verde(Verde/n);
      p2.set_azul(Azul/n);}
   return p2;                   }

bool Pixel:: operator==(Pixel p2){
    bool a=false;
    float dif_rojo,dif_azul,dif_verde;
    dif_rojo=sqrt(pow(Rojo-p2.get_rojo(),2));
    dif_azul=sqrt(pow(Azul-p2.get_azul(),2));
    dif_verde=sqrt(pow(Verde-p2.get_verde(),2));
    if((dif_azul<0.05f)&&(dif_rojo<0.05f)&&(dif_verde<0.05f))
        a=true;
    return a;                    }
