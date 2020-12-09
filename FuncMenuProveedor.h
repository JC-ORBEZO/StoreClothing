#ifndef FUNCMENUPROVEEDOR_H_INCLUDED
#define FUNCMENUPROVEEDOR_H_INCLUDED
///MENÚ PROVEEDORES
/// PUNTO 1: CARGAR PROVEEDOR
void cargarProveedor(){
Proveedor Proba;
int cantidad=0;
cout<<"CANTIDAD DE PROVEEDORES A CARGAR: ";
cin>>cantidad;
cout<<endl;
for (int i=1;i<=cantidad ;i++ ){
    //system("cls");
    Proba.cargarProveedor();
    cout<<endl;
if(Proba.guardarProveedorEnDisco()==true)cout<<"PROVEEDOR CORRECTAMENTE REGISTRADO"<<endl;
else cout<<"ERROR, PROVEEDOR NO REGISTRADO"<<endl;
}
}

///PUNTO 2: ELIMINAR PROVEEDOR
void eliminarProveedorPorID(){
cout<<"ELIMINAR PROVEEDOR: "<<endl;
cout<<endl;
Proveedor Aux;
int a=0;
int pos=0;
FILE *p;
p=fopen("Proveedores.dat","rb+");
cin.ignore();
char proveedor[20];
cout<<"ID PROVEEDOR: ";
cin.getline(proveedor,20,'\n');
if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
}
    while(fread(&Aux,sizeof (Proveedor),1,p)){
    if(strcmp(Aux.getCod_Proveedor(),proveedor)==0){
    cout<<endl;
    ///if(Aux.getActivoProveedor()==false){
    ///    cout<<"EL PROVEEDOR YA FUE DADO DE BAJA"<<endl;
    ///    return;
    ///}
    Aux.setActivoProveedor(false);
    if(Aux.guardarProveedorEnDisco(pos)==true){
        cout<<"PROVEEDOR DADO DE BAJA"<<endl;
        return;
    }else{
    cout<<"NO SE PUDO ELIMNAR AL PROVEEDOR"<<endl;
    }
    a++;
    }
    pos++;
  }
  fclose(p);

if(a==0){
        cout<<endl;
        cout<<"EL ID PROVEEDOR INGRESADO NO EXISTE"<<endl;
}
}

///PUNTO 3: LISTAR TOTALIDAD DE PROVEEDORES
//DENTRO DE LOS MÉTODOS

///PUNTO 4: BUSCAR POR PROVEEDOR POR ID
void mostrarProveedorPorID(){
cout<<"BUSCAR PROVEEDOR: "<<endl;
cout<<endl;
Proveedor Aux;
int a=0;
FILE *p;
p=fopen("Proveedores.dat","rb+");
cin.ignore();
char proveedor[20];
cout<<"ID PROVEEDOR: ";
cin.getline(proveedor,20,'\n');
if(p==NULL)cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
else{
    while(fread(&Aux,sizeof (Proveedor),1,p)){
    if(strcmp(Aux.getCod_Proveedor(),proveedor)==0){
    cout<<endl;
    Aux.mostrarProveedor();
    a++;
    }
  }
  fclose(p);
}
if(a==0){
        cout<<endl;
        cout<<"EL ID PROVEEDOR INGRESADO NO EXISTE"<<endl;
}
}
#endif // FUNCMENUPROVEEDOR_H_INCLUDED

/*
void mostrarClientePorID(){
cout<<"MOSTRAR CLIENTE"<<endl;
Cliente Aux;
FILE *p;
char dni[30];
cout<<"INGRESAR DNI CLIENTE: ";
cin.getline(dni,30,'\n');
p=fopen("ClientesRT.dat","rb");
if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return;
}
while(fread(&Aux,sizeof (Cliente),1,p)){
    if(strcmp(Aux.getDni_Cliente(),dni)==0){
        Aux.mostrarCliente();
    }
}
fclose(p);
}
*/
