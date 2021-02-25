#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Vendedor.h"

int Vendedor::buscarPosicion(const char *codVendedor){
    int pos=0;
    FILE *p;
    p=fopen("VendedoresNEW.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Vendedor),1,p)){
    if(strcmp(codigo_Vendedor,codVendedor)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

    int Vendedor::buscarPosicion2(char *codVendedor){
    int pos=0;
    FILE *p;
    p=fopen("VendedoresNEW.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Vendedor),1,p)){
    if(strcmp(codigo_Vendedor,codVendedor)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }


    void Vendedor::cargarVendedor(){
    activo=false;
    cout<<"CODIGO VENDEDOR: ";
    cin.getline(codigo_Vendedor,20,'\n');

    while(strlen(codigo_Vendedor)==0){
    cout<<"NO PUEDE HABER ESPACIOS EN BLANCO, VUELVA A INTENTARLO"<<endl;
    cout<<"CODIGO VENDEDOR: ";
    cin.getline(codigo_Vendedor,20,'\n');
    }
    cout<<"NOMBRE Y APELLIDO: ";
    cin.getline(nombre_Vendedor,20,'\n');
    while(strlen(nombre_Vendedor)==0){
    cout<<"NO PUEDE HABER ESPACIOS EN BLANCO, VUELVA A INTENTARLO"<<endl;
    cout<<"NOMBRE Y APELLIDO: ";
    cin.getline(nombre_Vendedor,20,'\n');
    }
    strcpy(dni_Vendedor,codigo_Vendedor);
    cout<<"CLAVE ACCESO: ";
    cin.getline(claveAcceso,20,'\n');
    activo=true;
    }

    void Vendedor::mostrarVendedor(){
    if(activo==true){
    cin.ignore();
    cout<<"CODIGO VENDEDOR:   "<<codigo_Vendedor<<endl;
    cout<<"NOMBRE Y APELLIDO: "<<nombre_Vendedor<<endl;
    cout<<"DNI:               "<<dni_Vendedor<<endl;
    }
    }

    void Vendedor::mostrarVendedor2(int b){
    if(activo==true){
    rlutil::locate(3,b);cout<<codigo_Vendedor;
    rlutil::locate(23,b);cout<<nombre_Vendedor;
    rlutil::locate(42,b);cout<<dni_Vendedor<<endl;
    }
    }

    bool Vendedor::guardarVendedorEnDisco(int posicion){
    FILE *p;
    bool grabo;
    if(posicion==-1){
        p=fopen("VendedoresNEW.dat","ab");
        if(p==NULL) return false;
    }else{
        p=fopen("VendedoresNEW.dat","rb+");
        if(p==NULL) return false;
        else fseek(p,posicion*sizeof (Vendedor),0);
    }
    grabo=fwrite(this,sizeof (Vendedor),1,p);
    fclose(p);
    return grabo;
    }

    ///LEER EN DISCO
    bool Vendedor::leerVendedorEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("VendedoresNEW.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Vendedor),0);
    leyo=fread(this,sizeof (Vendedor),1,p);
    fclose(p);
    return leyo;
    }
