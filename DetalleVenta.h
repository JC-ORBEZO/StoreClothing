#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED

///CLASE DETALLE VENTA
class DetalleVenta{
private:
    int codigo_Venta_DV;
    char codigoProducto_DV[20];
    int cantidad_DV;
    float precioVenta_DV;
    bool activo;
public:
    void cargar();
    void mostrar();
    bool guardarEnDisco(int = -1);
    void listarDetallesVenta();

    ///setts
    void setCodigo_Venta_DV(int);
    void setPrecioVenta_DV(float precio){
    precioVenta_DV=precio;}
    void setActivo(bool a){
    activo=a;
    };
    ///getts
    int getCodigo_Venta(){
    return codigo_Venta_DV;
    }
    float getPrecioVenta_DV(){
    return precioVenta_DV;}
    const char *getCodigoProducto_DV(){
    return codigoProducto_DV;
    }
    int getCantidad_DV(){
    return cantidad_DV;}
    bool getActivo(){
    return activo;
    }


};

    void DetalleVenta::setCodigo_Venta_DV(int cad){
    codigo_Venta_DV=cad;
    }

    void DetalleVenta::cargar(){
    activo=false;
    //cout<<"CODIGO DE VENTA :     ";
    //cin.getline(codigo_Venta_DV,20,'\n');
    cin.ignore();
    cout<<"CODIGO PRODUCTO :     ";
    cin.getline(codigoProducto_DV,20,'\n');
    cout<<"CANTIDAD        :     ";
    cin>>cantidad_DV;
    ///cout<<"PRECIO DE VENTA :     ";
    ///cin>>precioVenta_DV;
    activo=true;
    }

    void DetalleVenta::mostrar(){
    if(activo==true){
    cout<<"CODIGO DE VENTA :     "<<codigo_Venta_DV<<endl;
    cout<<"CODIGO PRODUCTO :     "<<codigoProducto_DV<<endl;
    cout<<"CANTIDAD        :     "<<cantidad_DV<<endl;
    cout<<"PRECIO DE VENTA :     "<<precioVenta_DV<<endl;
    }
    }

    bool DetalleVenta::guardarEnDisco(int posicion){
    bool grabo;
    FILE *p;

    if(posicion== -1){
       p=fopen("DetalleVentaRT.dat","ab");                              ///AHORA
       if(p==NULL)return false;
    }else{
        p=fopen("DetalleVentaRT.dat","ab+");
       if(p==NULL)return false;
       else fseek(p,posicion*sizeof (DetalleVenta),0);
    }
    grabo=fwrite(this,sizeof (DetalleVenta),1,p);
    fclose(p);
    return grabo;
    }

    ///LISTAR DETALLES DE VENTA
    void DetalleVenta::listarDetallesVenta(){
    FILE *p;
    p=fopen("DetalleVentaRT.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    while(fread(this ,sizeof (DetalleVenta), 1,p)){
    mostrar();
    cout<<endl;
    }
    fclose(p);
    return;
    }

#endif // DETALLEVENTA_H_INCLUDED
