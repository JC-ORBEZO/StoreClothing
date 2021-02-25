#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Producto.h"

void Producto::setCodProducto_P(char *codP){
    strcpy(codProducto_P,codP);
    }

    void Producto::setNombre_Producto_P(char *codN){
    strcpy(nombre_Producto_P,codN);
    }

    void Producto::setCodProveedor_P(char *codProv){
    strcpy(codProveedor_P,codProv);
    }

    void Producto::setPrecioVentaProducto_P(float pvp){
    precioVentaProducto_P=pvp;
    }

    void Producto::setPrecioCompraProducto_P(float pcp){
    precioCompraProducto_P=pcp;
    }

    void Producto::setStockProducto_P(int sp){
    stockProducto_P=sp;
    }

    void Producto::setTalle_Producto(char *t){
    strcpy(talle_Producto,t);
    }

    ///LISTAR PRODUCTOS

    void Producto::listarProductosID(){
    int a=3;
    FILE *p;
    p=fopen("ProductosNEW.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    cout<<" COD PRODUCTO"<<"    NOMBRE PRODUCTO "<<"   COD PROVEEDOR"<<"   PRECIO VENTA"<<"   PRECIO COMPRA"<<"   STOCK"<<"   TALLE"<<endl;
    cout<<" -------------------------------------------------------------------------------------------------"<<endl;
    while(fread(this ,sizeof (Producto), 1,p)){

    mostrarProducto2(a);
    a++;
    }
    fclose(p);
    return;
    }

    ///FUNCION ÓPTIMA
/**
    void listarProductosID(){
    Producto Reg;
    FILE *p;
    p=fopen("ProductosNEW.dat","rb");
    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    while(fread(&Reg ,sizeof (Producto), 1,p)){
    Reg.mostrarProducto();
    cout<<endl;
    }
    fclose(p);
    }
*/

    /**char Producto::getCodProducto_P(){
    return codProducto_P;
    }

    char Producto::getNombre_Producto_P(){
    return nombre_Producto_P;
    }

    char Producto::getCodProveedor_P(){
    return codProveedor_P;
    }*/

    float Producto::getPrecioVentaProducto_P(){
    return precioVentaProducto_P;
    }

    float Producto::getPrecioCompraProducto_P(){
    return precioCompraProducto_P;
    }

    int Producto::getStockProducto_P(){
    return stockProducto_P;
    }
    /**
    char Producto::getTalle_Producto(){
    return talle_Prod;
    }*/

    Producto::Producto(){
    strcpy(codProducto_P,"-");
    strcpy(nombre_Producto_P,"-");
    strcpy(codProveedor_P,"-");
    precioCompraProducto_P=0;
    precioVentaProducto_P=0;
    stockProducto_P=0;
    strcpy(talle_Producto,"-");
    }

    ///MOSTRAR PRODUCTO
    void Producto::mostrarProducto(){
    cin.ignore();
    cout<<"CODIGO PRODUCTO:  "<<codProducto_P<<endl;
    cout<<"NOMBRE PRODUCTO:  "<<nombre_Producto_P<<endl;
    cout<<"CODIGO PROVEEDOR: "<<codProveedor_P<<endl;
    cout<<"PRECIO VENTA:     "<<precioVentaProducto_P<<endl;
    cout<<"PRECIO COMPRA:    "<<precioCompraProducto_P<<endl;
    cout<<"STOCK:            "<<stockProducto_P<<endl;
    cout<<"TALLE:            "<<talle_Producto<<endl;

    }

    void Producto::mostrarProducto2(int b){
    cin.ignore();
    rlutil::locate(3,b);cout<<codProducto_P;
    rlutil::locate(23,b);cout<<nombre_Producto_P;
    rlutil::locate(40,b);cout<<codProveedor_P;
    rlutil::locate(56,b);cout<<precioVentaProducto_P;
    rlutil::locate(73,b);cout<<precioCompraProducto_P;
    rlutil::locate(86,b);cout<<stockProducto_P;
    rlutil::locate(95,b);cout<<talle_Producto<<endl;


    }

    ///CARGAR PRODUCTO
    void Producto::cargarProducto(){
    activo=false;
    cout<<"CODIGO PRODUCTO:  ";
    cin.getline(codProducto_P,20,'\n');
    while(strlen(codProducto_P)==0){
    cout<<"NO PUEDEN HABER ESPACIOS EN BLANCO, VUELVA A INTENTRLO."<<endl;
    cout<<"CODIGO PRODUCTO:  ";
    cin.getline(codProducto_P,20,'\n');
    }
    cout<<"NOMBRE PRODUCTO:  ";
    cin.getline(nombre_Producto_P,20,'\n');
    while(strlen(nombre_Producto_P)==0){
    cout<<"NO PUEDEN HABER ESPACIOS EN BLANCO, VUELVA A INTENTRLO."<<endl;
    cout<<"NOMBRE PRODUCTO:  ";
    cin.getline(nombre_Producto_P,20,'\n');
    }
    cout<<"CODIGO PROVEEDOR: ";
    cin.getline(codProveedor_P,20,'\n');
    while(strlen(codProveedor_P)==0){
    cout<<"NO PUEDEN HABER ESPACIOS EN BLANCO, VUELVA A INTENTRLO."<<endl;
    cout<<"CODIGO PROVEEDOR: ";
    cin.getline(codProveedor_P,20,'\n');
    }
    cout<<"PRECIO VENTA:     ";
    cin>>precioVentaProducto_P;
    while(precioVentaProducto_P<=0){
    cout<<"PRECIO DE VENTA NO VALIDO, VUELVA A INTENTARLO"<<endl;
    cout<<"PRECIO VENTA:     ";
    cin>>precioVentaProducto_P;
    }
    cout<<"PRECIO COMPRA:    ";
    cin>>precioCompraProducto_P;
    while(precioCompraProducto_P<=0){
    cout<<"PRECIO DE COMPRA NO VALIDO, VUELVA A INTENTARLO"<<endl;
    cout<<"PRECIO COMPRA:    ";
    cin>>precioCompraProducto_P;
    }
    cout<<"STOCK:            ";
    cin>>stockProducto_P;
    cin.ignore();
    while(stockProducto_P<=0){
    cout<<"STOCK NO VALIDO, VUELVA A INTENTARLO"<<endl;
    cout<<"STOCK:            ";
    cin>>stockProducto_P;
    }
    cout<<"TALLE:            ";
    cin.getline(talle_Producto,5,'\n');
    activo=true;
    }

    ///GUARDAR EN DISCO
    bool Producto::guardarProductoEnDisco(int posicion){
    bool grabo;
    FILE *p;
    if(posicion== -1){
        p=fopen("ProductosNEW.dat","ab");    ///AHORA
        if(p==NULL){
        return false;
        }
    }else{
        p=fopen("ProductosNEW.dat","rb+");
        if(p==NULL){
        return false;
        }
        fseek(p,posicion*sizeof (Producto),0);
    }
    grabo=fwrite(this,sizeof (Producto),1,p);
    fclose(p);
    return grabo;
    }

    /*///GUARADAR EN DISCO DE MUESTRA
        bool Examen::guardarEnDisco(int posicion){
        bool grabo;
        FILE *p;
        if (posicion == -1){
            p = fopen("examenes.dat", "ab");
            if (p == NULL){
                return false;
            }
        }
        else{
            p = fopen("examenes.dat", "rb+");
            if (p == NULL){
                return false;
            }
            fseek(p, posicion * sizeof(Examen), 0);
        }
        grabo = fwrite(this, sizeof(Examen), 1, p);
        fclose(p);
        return grabo;
    }*/

    ///LEER EN DISCO
    bool Producto::leerProductoEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("ProductosNEW.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Producto),0);
    leyo=fread(this,sizeof (Producto),1,p);
    fclose(p);
    return leyo;
    }

    ///BUSCAR POSICION: PARÁMETRO
    int Producto::buscarPosicion(const char *codProd){
    int pos=0;
    FILE *p;
    p=fopen("ProductosNEW.dat","rb+");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Producto),1,p)){
    if(strcmp(codProducto_P,codProd)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

    int Producto::buscarPosicion2(char *codProd){
    int pos=0;
    FILE *p;
    p=fopen("ProductosNEW.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Producto),1,p)){
    if(strcmp(codProducto_P,codProd)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

    ///LISTAR PRODUCTOS
     /*void Producto::listarProductoXid(){
        ///Producto proba;
        char cade[20];
        cout<<"INGRESE EL CODIGO PRODUCTO: ";
        cin.getline(cade,20,'\n');
        int pos;
        pos=buscarPosicion2(cade);
        if(leerProductoEnDisco(pos)==true) mostrarProducto();
        else cout<<"ERROR"<<endl;
        }*/

    /// MODIFICAR NOMBRE PRODUCTO
    void Producto::modificarNombreProducto(){
    int pos;
    char codProd[20];
    char nombreProd[20];
    cout<<"INGRESE CODIGO PRODUCTO: ";
    cin.getline(codProducto_P,20,'\n');
    cin.ignore();
    pos=buscarPosicion(codProducto_P);
    if(pos==-1){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }else{
        if(pos==-2){
        cout<<"CODIGO NO ENCONTRADO"<<endl;
        return;
    }
    }
    if(leerProductoEnDisco(pos)==true){
    cout<<"INGRESE UN NUEVO NOMBRE: ";
    cin>>nombreProd;
    ///cin.getline(nombreProd,20,'\n');
    strcpy(nombre_Producto_P,nombreProd);
    guardarProductoEnDisco(pos);
    }
    }

