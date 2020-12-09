#ifndef FUNCMENUPRODUCTOS_H_INCLUDED
#define FUNCMENUPRODUCTOS_H_INCLUDED

///IMPLEMENTACION DE FUNCIONES

///PUNTO 1: CARGAR PRODUCTO: PUEDE CARGAR LA CANTIDAD QUE SE NECESITE
void cargarProducto(){
int cantidad;
Producto Aux;
Proveedor Proba;
cout<<"CANTIDAD A CARGAR: ";
cin>>cantidad;
cout<<endl;
for (int i=1;i<=cantidad ;i++ ){
    cin.ignore();
    Aux.cargarProducto();
    int posicion;
    posicion=Proba.buscarPosicion(Aux.getCodProveedor_P());
    while(posicion<0){
        cout<<"CODIGO DE PROVEEDOR NO EXISTE, VUELVA A INTENTARLO"<<endl;
        char cadena[20];
        cout<<"CODIGO PROVEEDOR: ";
        cin.getline(cadena,20,'\n');
        Aux.setCodProveedor_P(cadena);
        posicion=Proba.buscarPosicion(Aux.getCodProveedor_P());
    }
        if(Aux.guardarProductoEnDisco()==true)cout<<"ARCHIVO AGREGADO"<<endl;
        else cout<<"ERROR, PRODUCTO NO AGREGADO"<<endl;
        cout<<endl;
}
}

///PUNTO 2: MODIFICAR PRECIO
void modificarPrecioProducto(){
    Producto Aux;
    float precioV;
    char cadeneta[20];
    cout<<"INGRESE EL CODIGO DE PRODUCTO:  ";
    cin.getline(cadeneta,20,'\n');
    int posicion;
    posicion=Aux.buscarPosicion2(cadeneta);
    if(posicion<0)cout<<"EL CODIGO DE PRODUCTO INGRESADO NO EXISTE"<<endl;
    else{
        if(Aux.leerProductoEnDisco(posicion)==true){
        cout<<"INGRESE EL NUEVO PRECIO DE VENTA: ";
        cin>>precioV;
        Aux.setPrecioVentaProducto_P(precioV);
        if(Aux.guardarProductoEnDisco(posicion)==true){
            cout<<"PRECIO DE VENTA FUE MODIFICADO"<<endl;
        }else{
            cout<<"EL PRECIO VENTA NO PUDO SER MODIFICADO"<<endl;
        }
    }else{
            cout<<"ERROR"<<endl;
    }
}
}
///AHORA!!!
///PUNTO 3: MODIFICAR STOCK
void modificarStockProducto(){
    Producto Aux;
    int stock;
    char cadeneta[20];
    cout<<"INGRESE EL CODIGO DE PRODUCTO:  ";
    cin.getline(cadeneta,20,'\n');
    int posicion;
    posicion=Aux.buscarPosicion2(cadeneta);
    if(posicion<0){cout<<"EL CODIGO DE PRODUCTO INGRESADO NO EXISTE"<<endl;
    }else{

        if(Aux.leerProductoEnDisco(posicion)==true){
        cout<<"CANTIDAD DE PRENDAS A AUMENTAR: ";
        cin>>stock;
        Aux.AumentarStock(stock);
        int pos=posicion;
        //FILE *pes;
        //pes=fopen("ProductosRT.dat","ab+");
        //fseek(pes,posicion*sizeof(Producto),0);
        //fwrite(&Aux,sizeof (Producto),1,pes);
        //fclose(pes);
        Aux.guardarProductoEnDisco(pos);
        //cout<<"POSICION: "<<posicion<<endl;
        cout<<"ARCHIVO GUARDADO"<<endl;
        }else{
            cout<<"ERROR, NO SE PUDO GUARDAR"<<endl;
    }
}
}


/// PUNTO 5: LISTAR PRODUCTO SEGÚN SU CODIGO PRODUCTO
void ListarProductoXid(){
Producto Aux;

char cadeneta[20];
cout<<"INGRESE EL CODIGO DE PRODUCTO:  ";
cin.getline(cadeneta,20,'\n');
int posicion;
posicion=Aux.buscarPosicion2(cadeneta);
if(posicion<0)cout<<"EL CODIGO PRODUCTO INGRESADO NO EXISTE"<<endl;
else{
    if(Aux.leerProductoEnDisco(posicion)==true){
        Aux.mostrarProducto();
}else{
        cout<<"ERROR"<<endl;
}
}
}


#endif // FUNCMENUPRODUCTOS_H_INCLUDED
