#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Venta.h"

///LEER EN DISCO
    bool Venta::leerVentaEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("VentasNEW.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Venta),0);
    leyo=fread(this,sizeof (Venta),1,p);
    fclose(p);
    return leyo;
    }

    void Venta::listarVentas(){
    FILE *p;
    p=fopen("VentasNEW.dat","rb");
    int b=3;
    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    cout<<" CODIGO DE VENTA  "<<"  VENDEDOR "<<"  DNI CLIENTE "<<"     FECHA  "<<"    INGRESO TOTAL   "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    while(fread(this ,sizeof (Venta), 1,p)){
    mostrarVenta2(b);
    b++;
    cout<<endl;
    }
    cout<<endl<<endl<<endl;
    fclose(p);
    return;
    }


    void Venta::cargarVenta(){
    activo=false;
    //cout<<"CODIGO DE VENTA:           ";///TIENE QUE SER UN AUTONUMERICO
    //cin.getline(codigo_Venta,20,'\n');
    cout<<"DNI VENDEDOR:              ";
    cin.getline(codigoVendedor_Venta,20,'\n');
    cout<<"DNI CLIENTE:               ";
    cin.getline(dni_Cliente_Venta,20,'\n');
    //fecha_Venta.cargarFecha();
    cout<<"NUMERO DE TIPOS DE PRENDA: ";
    cin>>cantidad_Ventas;
    /*for (int i=1;i<= cantidad_Ventas;i++ ){
        system("cls");
        cin.ignore();
        DetaVenta.cargar();
        DetaVenta.guardarEnDisco();
    }*/

    ///cout<<"INGRESO TOTAL:             ";
    ///cin>>totalIngreso_Venta;
    activo=true;
    }

    void Venta::mostrarVenta(){
    if(activo==true){
    cin.ignore();
    cout<<"CODIGO DE VENTA:      "<<codigo_Venta<<endl;
    cout<<"VENDEDOR       :      "<<codigoVendedor_Venta<<endl;
    cout<<"DNI CLIENTE    :      "<<dni_Cliente_Venta<<endl;
    fecha_Venta.mostrarFecha2();///FALTA COMPLETAR
    cout<<"INGRESO TOTAL  :      "<<totalIngreso_Venta<<endl;
    ///cout<<"BOOL: "<<activo<<endl;
    }
    }

    void Venta::mostrarVenta2(int b){
    if(activo==true){
    cin.ignore();
    ///cout<<" CODIGO DE VENTA "<<" VENDEDOR "<<" DNI CLIENTE "<<" FECHA "<<" INGRESO TOTAL "<<endl;
    rlutil::locate(8,b);cout<<codigo_Venta;
    rlutil::locate(22,b);cout<<codigoVendedor_Venta;
    rlutil::locate(33,b);cout<<dni_Cliente_Venta;
    rlutil::locate(47,b);fecha_Venta.mostrarFecha();///FALTA COMPLETAR
    rlutil::locate(65,b);cout<<totalIngreso_Venta<<endl;
    ///cout<<"BOOL: "<<activo<<endl;
    }
    }

    bool Venta::guardarVentaEnDisco(int posicion){
    FILE *p;
    bool grabo;
    if(posicion== -1){
        p=fopen("VentasNEW.dat","ab");                       ///AHORA
        if(p==NULL)return false;
    }else{
        p=fopen("VentasNEW.dat","rb+");
        if(p==NULL) return false;
        else fseek(p,posicion*sizeof (Venta),0);
    }
    grabo=fwrite(this,sizeof (Venta),1,p);
    fclose(p);
    return grabo;
    }
