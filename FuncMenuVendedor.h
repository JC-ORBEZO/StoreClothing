#ifndef FUNCMENUVENDEDOR_H_INCLUDED
#define FUNCMENUVENDEDOR_H_INCLUDED

#include "Vendedor.h"
///EVALUA SI TIENE POSICION VALIDA EN EL ARCHIVO
void evaluaFuncionPosicion(int pos){
if(pos== -1){
    cout<<"NO SE PUDO ABRIR UN ARCHIVO"<<endl;
}else{
    if(pos== -2){
    cout<<"VENDEDOR NO REGISTRADO"<<endl;
    }else{
    cout<<"INFORMACION CORRECTA"<<endl;
    }
}
}

///BUSCAR POSICION DE VENDEDOR
int posicionVendedor(){
    Vendedor Aux;
    cin.ignore();
char DNIEmpleado[20];
cout<<"INGRESE DNI EMPLEADO: ";
cin.getline(DNIEmpleado,20,'\n');
int pos=0;
FILE *p;
p=fopen("VendedoresNEW.dat","rb");
if(p==NULL)return -1;
while(fread(&Aux,sizeof(Vendedor),1,p)){
    if(strcmp(Aux.getCodigo_Vendedor(),DNIEmpleado)==0){
        fclose(p);
        return pos;
    }else{
    pos++;
    }
}
fclose(p);
return -2;
}

/// PUNTO 1)
//RESUELTO CON MÉTODOS DE CLASS VENDEDOR

/// PUNTO 2)
void bajaVendedor(){
cout<<"EMPLEADO A DAR DE BAJA"<<endl;
cout<<endl;
Vendedor Aux;
cin.ignore();
char cadena[30];
cout<<"CODIGO EMPLEADO: ";
cin.getline(cadena,30,'\n');
cout<<endl;
int pos;
pos=Aux.buscarPosicion2(cadena);
if(pos<0){
    evaluaFuncionPosicion(pos);
}else{
Aux.leerVendedorEnDisco(pos);
Aux.setActivo(false);
if(Aux.guardarVendedorEnDisco(pos)==true)cout<<"EMPLEADO DADO DE BAJA"<<endl;
else cout<<"NO SE PUDO REALIZAR"<<endl;
}

}

/// PUNTO 3)
void listarVendedores(){
cout<<"LISTA DE VENDEDORES: "<<endl;
cout<<endl;
Vendedor Aux;
FILE *p;
p=fopen("VendedoresNEW.dat","rb");
if(p==NULL){
    cout<<"NO SE PUDO ABRIR ARCHIVO"<<endl;
    return;
}
cout<<" CODIGO VENDEDOR      "<<"   NOMBRE       "<<"    DNI "<<endl;
cout<<"----------------------------------------------"<<endl;
int b=5;
while(fread(&Aux,sizeof (Vendedor),1,p)){
    Aux.mostrarVendedor2(b);
    b++;
}
cout<<endl<<endl<<endl;
fclose(p);
}

/// PUNTO 4)
void listarVendeorPorID(){
cout<<"LISTAR VENDEDOR POR ID"<<endl;
cout<<endl;
Vendedor Aux;
cin.ignore();
char cadena[30];
cout<<"CODIGO EMPLEADO: ";
cin.getline(cadena,30,'\n');
cout<<endl;
int pos;
pos=Aux.buscarPosicion2(cadena);
if(pos<0){
    evaluaFuncionPosicion(pos);
}else{
Aux.leerVendedorEnDisco(pos);
cout<<" CODIGO VENDEDOR      "<<"   NOMBRE       "<<"    DNI "<<endl;
cout<<"----------------------------------------------"<<endl;
Aux.mostrarVendedor2(7);
}
}



#endif // FUNCMENUVENDEDOR_H_INCLUDED
