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
    void mostrar2(int);
    bool guardarEnDisco(int = -1);
    bool leerDetalleVentaEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("DetalleVentaNEW","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(DetalleVenta),0);
    leyo=fread(this,sizeof (DetalleVenta),1,p);
    fclose(p);
    return leyo;
    }
    void listarDetallesVenta();

    ///setts
    void setCodigo_Venta_DV(int);
    void setPrecioVenta_DV(float precio){
    precioVenta_DV=precio;}
    void setActivo(bool a){
    activo=a;
    };
    ///getts
    int getCodigo_VentaDV(){
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



#endif // DETALLEVENTA_H_INCLUDED
