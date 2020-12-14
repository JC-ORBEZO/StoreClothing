#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
///PROTOTIPOS DE FUNCIONES
void cargarProducto();
void modificarPrecioProducto();
void modificarStockProducto();

void ListarProductoXid();
/**
///FUNCION DE ACCESO
void AccesoEmpleados(){
Vendedor Reg;
int pos=0;
char cadena[30];
char clave[30];
rlutil::locate(42,7);
cout<<"ACCESO DE PERSONAL STORE CLOTHING"<<endl;
cout<<endl;
cin.ignore();
rlutil::locate(42,10);
cout<<"CODIGO EMPLEADO: ";
cin.getline(cadena,30,'\n');
cout<<endl;
while(Reg.leerVendedorEnDisco(pos)){
pos=pos+1;
if(strcmp(Reg.getCodigo_Vendedor(),cadena)==0){
rlutil::locate(42,11);
cout<<"CLAVE:           ";
cin.getline(clave,30,'\n');
}else{

if(strcmp(Reg.getClaveAcceso(),clave)==0){
menuAccesoEmpleados();
system("pause");
return;
}else{
cout<<"LOS DATOS INGRESADOS NO COINCIDEN, VUELVA A INTENTARLO"<<endl;
return;
}
}
}
system("pause");
}


void AccesoAdministrador(){

}
*/
#endif // PROTOTIPOS_H_INCLUDED
