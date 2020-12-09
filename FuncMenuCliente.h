#ifndef FUNCMENUCLIENTE_H_INCLUDED
#define FUNCMENUCLIENTE_H_INCLUDED
///PUNTO 1: CARGAR Y GUARDAR EN DISCO
//MÉTODOS DEL OBJETO CLIENTE

///PUNTO 2: LISTAR CLIENTE X DNI
void mostrarClientePorID(){
cout<<"MOSTRAR CLIENTE"<<endl;
Cliente Aux;
FILE *p;
char dni[30];
cin.ignore();
cout<<"INGRESAR DNI CLIENTE: ";
cin.getline(dni,30,'\n');
p=fopen("ClientesRT.dat","rb");
if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return;
}
while(fread(&Aux,sizeof (Cliente),1,p)){
    if(strcmp(Aux.getDni_Cliente(),dni)==0){
        cout<<endl;
        Aux.mostrarCliente();
        return;
    }
}
fclose(p);
cout<<endl;
cout<<"CODIGO CLIENTE NO REGISTRADO"<<endl;
return;
}

///PUNTO 3: LISTAR TODOS LOS CLIENTES
void listarClientes(){
cout<<"LISTA GENERAL DE CLIENTES"<<endl;
Cliente Aux;
FILE *p;
p=fopen("ClientesRT.dat","rb");
if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return;
}
while(fread(&Aux,sizeof (Cliente),1,p)){
        cout<<endl;
        Aux.mostrarCliente();
}
fclose(p);
}

/////VERIFICAR EXISTENCIA DE CLIENTE EN LOS ARCHIVOS
//int verificarExistenciaDeCliente(){
//int posicion;
//
//cout<<
//
//
//}

#endif // FUNCMENUCLIENTE_H_INCLUDED
