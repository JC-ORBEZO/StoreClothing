#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;
#include "Prototipos.h"
#include "Funciones.h"
#include "Producto.h"
#include "Vendedor.h"
#include "Cliente.h"
#include "DetalleVenta.h"
#include "Fecha.h"
#include "Venta.h"
#include "Proveedor.h"
#include "Menues.h"
#include "FuncMenuProductos.h"
#include "FuncMenuVendedor.h"
#include "FuncMenuVenta.h"
#include "FuncMenuCliente.h"
#include "FuncMenuProveedor.h"
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

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::WHITE);
    int opc;
        while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                    CLOTHING STORE                     ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------     PRODUCTOS     -----------       ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  -----------     EMPLEADOS     -----------       ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  ------------      VENTAS     ------------       ***"<<endl;rlutil::locate(32,11);
        cout<<"***   4)  -----------    PROVEEDORES    -----------       ***"<<endl;rlutil::locate(32,12);
        cout<<"***   5)  -----------      CLIENTES     -----------       ***"<<endl;rlutil::locate(32,13);
        ///cout<<"***   6)  -----------      REPORTES     -----------       ***"<<endl;rlutil::locate(32,14);
        ///cout<<"***   7)  -----------   CONFIGURACION   -----------       ***"<<endl;rlutil::locate(32,15);
        cout<<""<<endl;rlutil::locate(32,16);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,17);
        cout<<"**********************    0) SALIR     **********************"<<endl;rlutil::locate(32,18);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,19);
        cout<<"OPCION:";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        rlutil::cls();
        menuProductos();
        rlutil::anykey();
        break;
    case 2:
        rlutil::cls();
        menuEmpleados();
        rlutil::anykey();
        break;
    case 3:
        rlutil::cls();
        menuVentas();
        rlutil::anykey();
        break;
    case 4:
        rlutil::cls();
        menuProveedores();
        rlutil::anykey();
        break;
    case 5:
        rlutil::cls();
        menuClientes();
        rlutil::anykey();
        break;
    case 6:
        rlutil::cls();
        menuReportes();
        rlutil::anykey();
        break;
    case 7:
        rlutil::cls();
        ///menuConfiguracion();
        rlutil::anykey();
        break;
    case 0:return 0;
        break;
    default:
        rlutil::locate(52,2);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
        system("pause");
    }

    return 0;
}

void menuProductos(){
    int opc;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                    MENU PRODUCTOS                    ***"<<endl;rlutil::locate(32,5);
        cout<<"************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------   NUEVO PRODUCTO   -----------     ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  -----------  MODIFICAR PRECIOS -----------     ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  -----------   MODIFICAR STOCK  -----------     ***"<<endl;rlutil::locate(32,11);
        cout<<"***   4)  -----------  LISTAR PRODUCTOS  -----------     ***"<<endl;rlutil::locate(32,12);
        cout<<"***   5)  -----------    LISTAR POR ID   -----------     ***"<<endl;rlutil::locate(32,13);
        cout<<"";rlutil::locate(32,14);
        cout<<"************************************************************"<<endl;rlutil::locate(32,15);
        cout<<"***********************    0) SALIR    *********************"<<endl;rlutil::locate(32,16);
        cout<<"************************************************************"<<endl;rlutil::locate(32,17);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 0:
        return;
        break;
    case 1:
        cargarProducto();
        break;
    case 2:
        cin.ignore();
        modificarPrecioProducto();
        break;
    case 3:
        cin.ignore();
        modificarStockProducto();
        break;
    case 4:
        ///{
        ///Producto aux;
        ///aux.listarProductosID();
        ///}
        listarProductosID();
        break;
    case 5:
        cin.ignore();
        ListarProductoXid();
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
        system("pause");

    }
}

void menuEmpleados(){
    int opc;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                     MENU EMPLEADOS                    ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------   NUEVO VENDEDOR   -----------      ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  -----------  ELIMINAR VENDEDOR -----------      ***"<<endl;rlutil::locate(32,10);
        //cout<<"***   --  -----------  ----------------  -----------      ***"<<endl;rlutil::locate(32,11);
        //cout<<"***   --  -----------  ----------------  -----------      ***"<<endl;rlutil::locate(32,12);
        cout<<"***   3)  -----------  LISTAR VENDEDORES -----------      ***"<<endl;rlutil::locate(32,13);
        cout<<"***   4)  -----------   LISTAR POR ID    -----------      ***"<<endl;rlutil::locate(32,14);
        cout<<"";rlutil::locate(32,15);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,16);
        cout<<"***********************    0) SALIR    **********************"<<endl;rlutil::locate(32,17);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,18);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        cin.ignore();
        Vendedor auxil;
        auxil.cargarVendedor();
        if(auxil.guardarVendedorEnDisco()==true)cout<<"VENDEDOR AGREGADO"<<endl;
        else cout<<"ERROR, VENDEDOR NO AGREGADO"<<endl;
        break;
    case 2:
        bajaVendedor();
        break;
    case 3:
        listarVendedores();
        break;
    case 4:
        listarVendeorPorID();
        break;
    case 0:return;
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
        system("pause");
    }
}

void menuVentas(){
    int opc;
    Venta auxili;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"******                      VENTAS                    ******"<<endl;rlutil::locate(32,5);
        cout<<"************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  ------------    NUEVA VENTA    ------------    ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  ----------   LISTAR VENTA X ID   ----------    ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  ------------  ELIMINAR VENTA  -------------    ***"<<endl;rlutil::locate(32,11);
        cout<<"***   4)  ------  LISTAR VENTA POR DNI CLIENTE  -----    ***"<<endl;rlutil::locate(32,12);
        cout<<"***   5)  ------------    LISTAR VENTAS   -----------    ***"<<endl;rlutil::locate(32,13);
        cout<<"***   6)  ------   LISTAR INGRESOS POR MES    -------    ***"<<endl;rlutil::locate(32,14);
        cout<<"";rlutil::locate(32,15);
        cout<<"************************************************************"<<endl;rlutil::locate(32,16);
        cout<<"***********************    0) SALIR    *********************"<<endl;rlutil::locate(32,17);
        cout<<"************************************************************"<<endl;rlutil::locate(32,18);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        nuevaVenta();
        break;
    case 2:
        listarVentaXid();
        break;
    case 3:
        eliminarVenta();
        break;
    case 4:
        listarVentaPorDni();
        break;
    case 5:
         {
            Venta Aux;
            Aux.listarVentas();
        }
        break;
    case 6:
        ingresoPorMes();
            break;
    case 0:return;
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
    system("pause");
    }
}

void menuClientes(){
    int opc;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                     MENU CLIENTES                     ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------    NUEVO CLIENTE   -----------      ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  --------   MOSTRAR CLIENTE X DNI  --------      ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  -----------   LISTAR CLIENTES  -----------      ***"<<endl;rlutil::locate(32,11);
        cout<<"";rlutil::locate(32,12);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,13);
        cout<<"***********************    0) SALIR    **********************"<<endl;rlutil::locate(32,14);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,15);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        {Cliente Aux;
        cin.ignore();
        Aux.cargarCliente();
        if(Aux.guardarClienteEnDisco()==true)cout<<"GUARDADO EN DISCO"<<endl;
        else cout<<"NO PUDO SER GUARDAR EL ARCHIVO"<<endl;}
        break;
    case 2:
        mostrarClientePorID();
        break;
    case 3:
        listarClientes();
        break;
    case 0:return;
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
        system("pause");
    }
}

/// MENÚ PROVEEDORES
/// PUNTO 1: LISTO, TERMINADO
/// PUNTO 2: LISTO, TERMINADO
/// PUNTO 3: LISTO, TERMINADO
/// PUNTO 4: LISTO, TERMINADO
void menuProveedores(){
    int opc;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                    MENU PROVEEDORES                   ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  -----------   NUEVO PROVEEDOR   -----------     ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  -----------  ELIMINAR PROVEEDOR -----------     ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  -----------  LISTAR PROVEEDORES -----------     ***"<<endl;rlutil::locate(32,11);
        cout<<"***   4)  -----------   BUSCAR PROVEEDOR  -----------     ***"<<endl;rlutil::locate(32,12);
        cout<<"";rlutil::locate(32,13);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,14);
        cout<<"***********************    0) SALIR    **********************"<<endl;rlutil::locate(32,15);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,16);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        cargarProveedor();
        break;
    case 2:
        eliminarProveedorPorID();
        break;
    case 3:
        {Proveedor proba;
        proba.listarProveedoresID();}
        break;
    case 4:
        mostrarProveedorPorID();
        break;
    case 0:return;
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
    system("pause");
    }
}


void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout<<endl;
        rlutil::locate(32,2);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,3);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,4);
        cout<<"***                      MENU REPORTES                    ***"<<endl;rlutil::locate(32,5);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,6);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,7);
        cout<<"";rlutil::locate(32,8);
        cout<<"***   1)  ---------  LISTAR INGRESOS X MES  ---------     ***"<<endl;rlutil::locate(32,9);
        cout<<"***   2)  --------- LISTAR INGRESOS ANUALES ---------     ***"<<endl;rlutil::locate(32,10);
        cout<<"***   3)  --------- LISTAR VENTA POR CODIGO ---------     ***"<<endl;rlutil::locate(32,11);
        cout<<"***   4)  --------- LISTAR PRODUCTO S/STOCK ---------     ***"<<endl;rlutil::locate(32,12);
        cout<<"";rlutil::locate(32,13);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,14);
        cout<<"***********************    0) SALIR    **********************"<<endl;rlutil::locate(32,15);
        cout<<"*************************************************************"<<endl;rlutil::locate(32,16);
        cout<<"OPCION: ";cin>>opc;
        system("cls");
        switch(opc){
    case 1:
        cargarProveedor();
        break;
    case 2:
        eliminarProveedorPorID();
        break;
    case 3:
        {Proveedor proba;
        proba.listarProveedoresID();}
        break;
    case 4:
        mostrarProveedorPorID();
        break;
    case 0:return;
        break;
    default:
        rlutil::locate(52,9);
        cout<<"OPCION INCORRECTA"<<endl;
        rlutil::setColor(rlutil::WHITE);
        }
    system("pause");
    }
}
