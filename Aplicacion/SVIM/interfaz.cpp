#include "interfaz.h"
using namespace std;

void Interfaz::menu(int argc, char *argv[]){
    unsigned n,n2;
    float n3,n4;
    string palabra,clave,valor,s1,s2,s3;
    Sistema s(argc,argv);
    float r,g,b;
    Metadatos datos;
    vector<string>claves;cout<<sizeof(unsigned short);
    cout<<"\n                      _-_-_-_-_-_-_-_SVIM_-_-_-_-_-_-_-_\n\n";
    while(n!=99){
    cout<<"MENU:"<<endl;
    cout<<"     1) Cargar imagen en memoria. "<<endl;
    cout<<"     2) Guardar imagen en archivo."<<endl;
    cout<<"     3) Mostrar atributos de la imagen."<<endl;
    cout<<"     4) Modificar atributos de la imagen."<<endl;
    cout<<"     5) Visualizar la imagen."<<endl;
    cout<<"     6) Aplicar procesamiento a la imagen."<<endl;
    cout<<"     7) Buscar valor a partir del codigo."<<endl;
    cout<<"     8) Desafio"<<endl;
    cout<<"     99) Salir"<<endl;
    cin>>n;//

    switch (n) {
        case 1:
            {
            cout<<"Ingrese nombre del archivo:";
            cin>>palabra;
            if(s.Cargar_Imagen(palabra))
                cout<<"Se cargo exitosamente la imagen.\n";
            else cout<<"Error al cargar el archivo\n";

            break;
            }
        case 2:
            {
             cout<<"Ingrese nombre del archivo:";
             cin>>palabra;
             if(s.Guardar_Imagen(palabra))
                cout<<"Se guardo exitosamente la imagen.\n";
             else cout<<"Error al guardar el archivo\n";

            break;
            }
        case 3:
            {
            cout<<"1-Cantidad de pixeles a lo ancho: "<<s.MostrarPixelX()<<endl;
            cout<<"2-Cantidad de pixeles a lo alto: "<<s.MostrarPixelY()<<endl;
            cout<<"3-Ancho de la imagen: "<<s.MostrarAncho()<<endl;
            cout<<"4-Alto de la imagen: "<<s.MostrarAlto()<<endl;
            cout<<"5-Unidad: "<<s.MostrarUnidad()<<endl;
            //cout<<"6-Intensidad de los pixeles:"<<endl<<s.MostrarImagen()<<endl;
            cout<<"6-Datos Personales:"<<endl;
            datos=s.MostrarMetadatos();
            claves=datos.get_metadatos();
            for(unsigned i=0;i<claves.size();i++)
                cout<<claves[i]<<":"<<datos.ver_valor(claves[i])<<endl;
            cout<<endl;
            break;
            }
        case 4:
            {
            cout<<"1- Pixeles en X y en Y."<<endl;
            cout<<"2-Ancho de la imagen."<<endl;
            cout<<"3-Alto de la imagen."<<endl;
            cout<<"4-Unidad."<<endl;
            cout<<"5-Modificar un pixel."<<endl;
            cout<<"6-Modificar Datos Personales."<<endl;
            cin>>n;
            switch (n){
                case 1:
                    {
                    cout<<"Ingrese cantidad de pixeles a lo ancho y alto:"<<endl;
                    cin>>n>>n2;
                    s.ModificarDimension(n,n2);
                    break;
                    }
                case 2:
                    {
                    cout<<"Ingrese valor:"<<endl;
                    cin>>n3;
                    s.ModificarAncho(n3);
                    break;
                    }
                case 3:
                    {
                    cout<<"Ingrese valor:"<<endl;
                    cin>>n4;
                    s.ModificarAlto(n4);
                    break;
                    }
                case 4:
                    {
                    cout<<"Ingrese unidad:"<<endl;
                    cin>>palabra;
                    s.ModificarUnidad(palabra);
                    break;
                    }
                case 5:
                    {
                    cout<<"ingrese posicion en x y en y del pixel:"<<endl;
                    cin>>n>>n2;
                    cout<<"ingrese los valores de rgb:"<<endl;
                    cin>>r>>g>>b;
                    if(!s.ModificarPixel(n,n2,r,g,b))
                        cout<<"error al cargar pixel."<<endl;

                    break;
                    }
                case 6:
                    {
                    cout<<"Ingrese clave y valor asociado:"<<endl;
                    cin>>clave>>valor;
                    s.ModificarMetadato(clave,valor);
                    break;
                  }
            }
            break;

            }
        case 5:
            {
            s.VisualizarImagen();
            break;
            }
        case 6:
              {
              cout<<"1-Filtro de color."<<endl;
              cout<<"2-Detector de estructuras."<<endl;
              cout<<"3-nuevo procesador.";
              cin>>n;
              if(n==1){
                  cout<<"Ingrese colores RGB:"<<endl;
                  cin>>r>>g>>b;
                  s.AplicarFiltro(r,g,b);
              }
              if(n==2){
                cout<<"Ingrese fila y columna:"<<endl;
                cin>>n>>n2;
                s.AplicarDetector(n2,n);
              }
              if(n==3){
                  s.osc();
              }
              break;
             }
        case 7:
            {
            cout<<"Ingrese codigo:"<<endl;
            cin>>clave;
            cout<<"El valor es: "<<s.MostrarValor(clave)<<endl;
            break;
             }
        case 8:
            {
                cout<<"Ingrese nombre del archivo:"<<endl;
                cin>>s3;
                cout<<"Ingrese clave:"<<endl;
                cin>>s1;
                cout<<"Ingrese valor:"<<endl;
                cin.get();
                getline(cin,s2);

                if(!s.temporizar(s1,s2,s3))
                    cout<<"No se encontro ningun metadato con esa clave o valor.\n";

                break;

   }

        case 99:
            {
             cout<<"Fin\n";
             break;
            }
        default:
            {
                cout<<"Opcion incorrecta."<<endl;
            }

    }
}

}



ostream& operator<<(ostream& salida,Imagen im){
    for(unsigned i=0;i<im.get_cantidad_py();i++){
        for(unsigned j=0;j<im.get_cantidad_px();j++)
            salida<<im(j,i).intensidad()<<"  ";
        salida<<endl;    }
    return salida;
}
