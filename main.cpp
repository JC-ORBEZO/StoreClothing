#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;
#include "Producto.h"
#include "Menues.h"
//int contadorVentas();
//void nuevaVenta();

///EXTRA PARA COMPROBAR EL FUNCIONAMIENTO DE LA FUNCION "CONTAR"
int contadorProductos(){
int cont=0;
FILE *p;
p=fopen("ProductosRT.dat","rb");
fseek(p,0,SEEK_END);
cont=ftell(p);
fclose(p);
cont=cont/sizeof(Producto);
return cont;
}

int main()
{
    /*
    Venta Aux;

    cout<<contadorVentas();
    Aux.leerVentaEnDisco(0);
    Aux.setCodigo_Venta(1);
    Aux.guardarVentaEnDisco(0);
    */
/*
    DetalleVenta Reg;
    Reg.cargar();
    Reg.guardarEnDisco();
    Reg.listarDetallesVenta();
*/
    /*
    Reg.leerDetalleVentaEnDisco(0);
    Reg.setCodigo_Venta_DV(1);
    Reg.guardarEnDisco(0);
    */
//int a=2;
    //rlutil::locate(2,a);cout<<"COD PRODUCTO";
    //rlutil::locate(17,a);cout<<"NOMBRE PRODUCTO";
    //system("pause");

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    int opc;
    while(true){
     system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                ACCESO - CLOTHING STORE                ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------     VENDEDORES    -----------       ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  -----------   ADMINISTRADOR   -----------       ***"<<endl;rlutil::locate(32,10);
        cout<<""<<endl;rlutil::locate(32,11);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,12);
        cout<<"**********************    0) SALIR     **********************"<<endl;rlutil::locate(32,13);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,14);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        rlutil::cls();
        menuAccesoEmpleados();
        //AccesoEmpleados();
        rlutil::anykey();
        break;
    case 2:
        rlutil::cls();
        menuAccesoAdminnistrador();
        rlutil::anykey();
        break;
    case 0:return 0;
        break;
    default:
        rlutil::locate(52,2);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
        //system("pause");
    }
    return 0;
}

