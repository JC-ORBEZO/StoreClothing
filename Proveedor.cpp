#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Proveedor.h"

///LISTAR PRODUCTOS
    void Proveedor::listarProveedoresID(){
    int b=3;
    FILE *p;
    p=fopen("ProveedoresNEW.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    cout<<" CODIGO PROVEEDOR  "<<"  NOMBRE PROVEEDOR  "<<"      TELEFONO      "<<"    DIRECCION   "<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    while(fread(this ,sizeof (Proveedor), 1,p)){
    mostrarProveedor2(b);
    cout<<endl;
    b++;
    }
    cout<<endl<<endl<<endl;
    fclose(p);
    return;
    }

///BUSCAR POSICION
    int Proveedor::buscarPosicion(const char *codProv){
    int pos=0;
    FILE *p;
    p=fopen("ProveedoresNEW.dat","rb+");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Proveedor),1,p)){
    if(strcmp(cod_Proveedor,codProv)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

void Proveedor::cargarProveedor(){
cin.ignore();
activoProveedor=false;
cout<<"CODIGO PROVEEDOR: ";
cin.getline(cod_Proveedor,20,'\n');
while(strlen(cod_Proveedor)==0){
cout<<"NO PUEDE DEJAR ESPACIOS EN BLANCO"<<endl;
cout<<"CODIGO PROVEEDOR: ";
cin.getline(cod_Proveedor,20,'\n');
}
cout<<"NOMBRE PROVEEDOR: ";
cin.getline(nombre_Proveedor,20,'\n');
while(strlen(nombre_Proveedor)==0){
cout<<"NO PUEDE DEJAR ESPACIOS EN BLANCO"<<endl;
cout<<"NOMBRE PROVEEDOR: ";
cin.getline(nombre_Proveedor,20,'\n');
}
cout<<"TELEFONO: ";
cin.getline(telefono_Proveedor,20,'\n');
while(strlen(telefono_Proveedor)==0){
cout<<"NO PUEDE DEJAR ESPACIOS EN BLANCO"<<endl;
cout<<"TELEFONO: ";
cin.getline(telefono_Proveedor,20,'\n');
}
cout<<"DIRECCION: ";
cin.getline(direccion_Proveedor,20,'\n');
while(strlen(direccion_Proveedor)==0){
cout<<"NO PUEDE DEJAR ESPACIOS EN BLANCO"<<endl;
cout<<"DIRECCION: ";
cin.getline(direccion_Proveedor,20,'\n');
}
activoProveedor=true;
}

void Proveedor::mostrarProveedor(){
if(activoProveedor==true){
cin.ignore();
cout<<"CODIGO PROVEEDOR:   "<<cod_Proveedor<<endl;
cout<<"NOMBRE PROVEEDOR:   "<<nombre_Proveedor<<endl;
cout<<"TELEFONO:           "<<telefono_Proveedor<<endl;
cout<<"DIRECCION:          "<<direccion_Proveedor<<endl;
//cout<<activoProveedor<<endl;
}
}

void Proveedor::mostrarProveedor2(int b){
if(activoProveedor==true){
cin.ignore();
//cout<<" CODIGO PROVEEDOR  "<<"  NOMBRE PROVEEDOR  "<<"  TELEFONO  "<<"  DIRECCION "<<endl;
rlutil::locate(7,b);cout<<cod_Proveedor;
rlutil::locate(23,b);cout<<nombre_Proveedor;
rlutil::locate(45,b);cout<<telefono_Proveedor;
rlutil::locate(62,b);cout<<direccion_Proveedor<<endl;
//cout<<activoProveedor<<endl;
}
}

bool Proveedor::guardarProveedorEnDisco(int posicion){
FILE *p;
bool grabo;
if(posicion==-1){
    p=fopen("ProveedoresNEW.dat","ab");
    if(p==NULL) return false;
}else{
    p=fopen("ProveedoresNEW.dat","rb+");
    if(p==NULL) return false;
    else fseek(p,posicion*sizeof (Proveedor),0);
}
grabo=fwrite(this,sizeof (Proveedor),1,p);
fclose(p);
return grabo;
}
