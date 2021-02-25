#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "DetalleVenta.h"

void DetalleVenta::setCodigo_Venta_DV(int cad){
    codigo_Venta_DV=cad;
    }

    void DetalleVenta::cargar(){
    activo=false;
    //cout<<"CODIGO DE VENTA :     ";
    //cin>>codigo_Venta_DV;
    cin.ignore();
    cout<<"CODIGO PRODUCTO :     ";
    cin.getline(codigoProducto_DV,20,'\n');
    cout<<"CANTIDAD        :     ";
    cin>>cantidad_DV;
    //cout<<"PRECIO DE VENTA :     ";
    //cin>>precioVenta_DV;
    activo=true;
    }

    void DetalleVenta::mostrar(){
    if(activo==true){
    //cout<<"CODIGO DE VENTA :     "<<codigo_Venta_DV<<endl;
    cout<<"CODIGO PRODUCTO :     "<<codigoProducto_DV<<endl;
    cout<<"CANTIDAD        :     "<<cantidad_DV<<endl;
    cout<<"PRECIO DE VENTA :     "<<precioVenta_DV<<endl;
    }
    }


    void DetalleVenta::mostrar2(int b){
    if(activo==true){
    //cout<<"CODIGO DE VENTA :     "<<codigo_Venta_DV<<endl;
    rlutil::locate(8,b);cout<<codigoProducto_DV;
    rlutil::locate(25,b);cout<<cantidad_DV;
    rlutil::locate(36,b);cout<<precioVenta_DV<<endl;
    }
    }

    bool DetalleVenta::guardarEnDisco(int posicion){
    bool grabo;
    FILE *p;

    if(posicion== -1){
       p=fopen("DetalleVentaNEW.dat","ab");
       if(p==NULL)return false;
    }else{
        p=fopen("DetalleVentaNEW.dat","rb+");
       if(p==NULL)return false;
       else fseek(p,posicion*sizeof (DetalleVenta),0);
    }
    grabo=fwrite(this,sizeof (DetalleVenta),1,p);
    fclose(p);
    return grabo;
    }

    ///LISTAR DETALLES DE VENTA
    void DetalleVenta::listarDetallesVenta(){
    FILE *p;
    p=fopen("DetalleVentaNEW.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    while(fread(this ,sizeof (DetalleVenta), 1,p)){
    mostrar();
    cout<<endl;
    }
    fclose(p);
    return;
    }
