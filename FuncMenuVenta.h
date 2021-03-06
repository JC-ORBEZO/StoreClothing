#ifndef FUNCMENUVENTA_H_INCLUDED
#define FUNCMENUVENTA_H_INCLUDED
///BUSCAR POSICION DE VENTA
int posicionVenta(){
    Venta Aux;
    cin.ignore();
int idVenta;
cout<<"INGRESE CODIGO DE VENTA: ";
cin>>idVenta;
cout<<endl;
int pos=0;
FILE *p;
p=fopen("VentasNEW.dat","rb");
if(p==NULL)return -1;
while(fread(&Aux,sizeof(Venta),1,p)){
    if(Aux.getCodigo_Venta()==idVenta){
        fclose(p);
        return pos;
    }else{
    pos++;
    }
}
fclose(p);
return -2;
}

int buscarPosVentaPorDniCliente(const char *dni){
Venta Aux;
    cin.ignore();
//int idVenta;
//cout<<"INGRESE CODIGO DE VENTA: ";
//cin>>idVenta;
cout<<endl;
int pos=0;
FILE *p;
p=fopen("VentasNEW.dat","rb");
if(p==NULL)return -1;
while(fread(&Aux,sizeof(Venta),1,p)){
    if(strcmp(Aux.getDni_Cliente_Venta(),dni)==0){
        fclose(p);
        return pos;
    }else{
    pos++;
    }
}
fclose(p);
return -2;
}

///BUSCAR POSICION DE DETALLE VENTA
int posicionDetalleVenta(int idVenta){
    DetalleVenta Aux;
    cin.ignore();
int pos=0;
FILE *p;
p=fopen("DetalleVentaNEW.dat","rb");
if(p==NULL)return -1;
while(fread(&Aux,sizeof(DetalleVenta),1,p)){
    if(Aux.getCodigo_VentaDV()==idVenta){
        fclose(p);
        return pos;
    }else{
    pos++;
    }
}
fclose(p);
return -2;
}

///CONTAR VENTAS EN ARCHIVO PARA EL AUTONUMERICO
int contadorVentas(){
int cont=0;
FILE *p;
p=fopen("VentasNEW.dat","rb");

fseek(p,0,SEEK_END);
cont=ftell(p);
fclose(p);
cont=cont/sizeof(Venta);
return cont;
}

///CONTAR DETALLES DE VENTA EN ARCHIVO PARA EL AUTONUMERICO
int contadorDetalleVenta(){
int cont=0;
FILE *p;
p=fopen("DetalleVentaNEW.dat","rb");

fseek(p,0,SEEK_END);
cont=ftell(p);
fclose(p);
cont=cont/sizeof(DetalleVenta);
return cont;
}

///PUNTO 1: NUEVA VENTA: SOLO ESTAR�A FALTANDO QUE SEA CAPAZ DE DISMINUIR EL STOCK SEG�N EL CONSUMO Y LA ALERTA FORRA ESA
void nuevaVenta(){
    Venta Proba;
    DetalleVenta Aux;
    Producto Reg;
    Vendedor Rap;
    Cliente Cli;
    struct Fechini prueba;
    cin.ignore();///AHORA
    Proba.cargarVenta();
    ///VERIFICAR QUE EL VENDEDOR EST� REGISTRADO
    int cont=Rap.buscarPosicion(Proba.getCodigoVendedor_Venta());
    if(cont<0){
        cout<<endl;
        cout<<"VENDEDOR NO REGISTRADO, VUELVA A INTENTARLO"<<endl;
        return;
    }
    ///VERIFICAR QUE CLIENTE EST� CORRECTAMENTE REGISTRADO
    int contador=Cli.buscarPosicion(Proba.getDni_Cliente_Venta());
    //cout<<contador<<endl;
    if(contador<0){
        cout<<endl;
        cout<<"CLIENTE NO REGISTRADO, VUELVA A INTENTARLO"<<endl;
        return;
    }

    float ingresoTotal=0;
    Proba.setCodigo_Venta(contadorVentas()+1);
    for (int i=1;i<=Proba.getCantidad_Ventas();i++ ){
        cin.ignore();
        int cadena;
        cadena=Proba.getCodigo_Venta();
        Aux.setCodigo_Venta_DV(cadena);

        Aux.cargar();

        float precio;
        int posicion;
        posicion=Reg.buscarPosicion(Aux.getCodigoProducto_DV());
        if(posicion== -1){
            cout<<"NO SE PUDO BUSCAR EL ARCHIVO"<<endl;
            system("pause");
            return;
        }else{
        if(posicion== -2){
            cout<<"EL CODIGO PRODUCTO NO EXISTE"<<endl;
            system("pause");
            return;
        }else{
        Reg.leerProductoEnDisco(posicion);
        precio=Reg.getPrecioVentaProducto_P();
        ///
        if(Reg.getStockProducto_P()>Aux.getCantidad_DV()){
        Reg.disminuirStock(Aux.getCantidad_DV());
        Reg.guardarProductoEnDisco(posicion);
        Aux.setPrecioVenta_DV(precio);
        ingresoTotal+=(Aux.getCantidad_DV()*Aux.getPrecioVenta_DV());
        Aux.guardarEnDisco();
        }else{
        cout<<endl;
        cout<<"PRODUCTO SIN STOCK"<<endl;
        }
        }
        }
        }
    prueba=hoy();
    Proba.setFecha_Venta(prueba);
if(ingresoTotal!=0){
    Proba.setTotalIngreso_Venta(ingresoTotal);
    Proba.guardarVentaEnDisco();
}

}

///PUNTO 2 LISTAR VENTA Y DETALLE DE VENTA X ID
void listarVentaXid(){
    Venta Aux;
    DetalleVenta Reg;
    cout<<"LISTAR VENTA POR ID"<<endl;
    cout<<endl;
int pos;
pos=posicionVenta();
if(pos<0){
    cout<<"EL ID INGRESADO NO EXISTE"<<endl;
    return;
}
Aux.leerVentaEnDisco(pos);
if(Aux.getActivo()==false){
    cout<<"VENTA YA DADA DE BAJA"<<endl;
    return;
}
cout<<" CODIGO DE VENTA  "<<"  VENDEDOR "<<"  DNI CLIENTE "<<"     FECHA  "<<"    INGRESO TOTAL   "<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
if(Aux.getActivo()==true){
   Aux.mostrarVenta2(7);
}

cout<<endl;
FILE *p;
p=fopen("DetalleVentaNEW.dat","rb+");
if(p==NULL){
    return;
}
cout<<"DETALLE: "<<endl;
cout<<endl;
cout<<"  CODIGO PRODUCTO  "<<" CANTIDAD "<<" PRECIO DE VENTA "<<endl;
cout<<"----------------------------------------------"<<endl;
int b=13;
while(fread(&Reg,sizeof(DetalleVenta),1,p)){
    if(Aux.getCodigo_Venta()==Reg.getCodigo_VentaDV()){
        if(Reg.getActivo()==true){
          Reg.mostrar2(b);
          b++;
        }

    }
}
cout<<endl<<endl<<endl;
}

///PUNTO 3 ELIMINAR VENTA
void eliminarVenta(){

int posi=0;
Producto Aux;
Venta Reg;
DetalleVenta Proba;
int posicion=posicionVenta();
Reg.leerVentaEnDisco(posicion);
if(Reg.getActivo()==false){
    cout<<"VENTA YA DADA DE BAJA"<<endl;
    return;
}

///         ///
FILE *p;
p=fopen("DetalleVentaNEW.dat","rb+");
if(p==NULL){
    return;
}
//cout<<"DETALLE: "<<endl;
//cout<<endl;
while(fread(&Proba,sizeof(DetalleVenta),1,p)){
/**AHORA*/    if(Proba.getCodigo_VentaDV()==Reg.getCodigo_Venta()){
        int pos=Aux.buscarPosicion(Proba.getCodigoProducto_DV());
        Aux.leerProductoEnDisco(pos);
        Aux.AumentarStock(Proba.getCantidad_DV());
        Aux.guardarProductoEnDisco(pos);

        //Proba.setActivo(false);
        //Proba.guardarEnDisco();NO HACE FALTA GUARDAR PUES NO SER�A LLAMADO
    }
}

Reg.setActivo(false);
Reg.guardarVentaEnDisco(posicion);
}

///PUNTO 4 LISTAR POR DNI CLIENTE
//1. INGRESAR DNI Y CORROBORAR EXISTENCIA DEL DNI EN ARCHIVO CLIENTES
//2. BUSCAR DNI EN ARCHIVO VENTAS Y SI LOS DNI COINCIDEN Y ACTIVO_VENTA ES TRUE, MOSTRAR ESA VENTA Y SUS DETALLES DE VENTA (ARCHIVO DETALLEVENTA)
//3. ARCHIVO VENTA/ DETALLE VENTA Y CLIENTES
//4.

void listarVentaPorDni(){
int b=8;
Venta Aux;
cin.ignore();
cout<<"LISTAR VENTA POR DNI CLIENTE"<<endl;
char dni[20];
cout<<"INGRESE DNI CLIENTE: ";
cin.getline(dni,20,'\n');
FILE *p;
p=fopen("VentasNEW.dat","rb");
if(p==NULL){
    cout<<"ERROR, NO SE PUDO ABRIR EL ARCHIVO VENTAS"<<endl;
    return;
}
if(buscarPosVentaPorDniCliente(dni)<0){
cout<<"DNI CLIENTE NO REGISTRADO"<<endl;
return;
}

cout<<endl;
cout<<" CODIGO DE VENTA  "<<"  VENDEDOR "<<"  DNI CLIENTE "<<"     FECHA  "<<"    INGRESO TOTAL   "<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
while(fread(&Aux,sizeof(Venta),1,p)){
    ///Aux.mostrarVenta();
    if(strcmp(Aux.getDni_Cliente_Venta(),dni)==0){
        cout<<endl;
        Aux.mostrarVenta2(b);
        b++;
    }
}
cout<<endl<<endl<<endl;
fclose(p);
}


///PUNTO 5




#endif // FUNCMENUVENTA_H_INCLUDED
