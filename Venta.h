#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

///CLASE VENTAS
class Venta{
private:
    int codigo_Venta;/// AUTONUMERICO
    char codigoVendedor_Venta[20];
    char dni_Cliente_Venta[20];
    Fecha fecha_Venta;
    int cantidad_Ventas;        /// EXTRA PARA ACOPLAR DETALLE VENTAS  "DUDOSO"
    DetalleVenta DetaVenta;   /// EXTRA PARA ACOPLAR DETALLE VENTAS
    float totalIngreso_Venta;
    bool activo;
public:
    void cargarVenta();
    void mostrarVenta();
    bool guardarVentaEnDisco(int = -1);
    void listarVentas();

    ///setter
    void setActivo(bool a){
    activo=a;
    };
    void setCodigo_Venta(int c){
    codigo_Venta=c;
    };
    void setCodigoVendedor_Venta(char *c);
    void setDni_Cliente_Venta(char *);
    void setFecha_Venta(Fecha f){/**fecha_Venta=f;*/};



    void setFecha_Venta(Fechini prueba){
    fecha_Venta.setDia(prueba.dia);
    fecha_Venta.setMes(prueba.mes);
    fecha_Venta.setAnio(prueba.anio);
    };


    void setTotalIngreso_Venta(float total){totalIngreso_Venta=total;};
    ///getters
    Fecha getFecha_Venta(){
    return fecha_Venta;
    }

    bool getActivo(){
    return activo;}
    int getCodigo_Venta(){
    return codigo_Venta;
    }
    const char *getCodigoVendedor_Venta(){
    return codigoVendedor_Venta;
    }
    const char *getDni_Cliente_Venta(){
    return dni_Cliente_Venta;
    }
    int getCantidad_Ventas(){return cantidad_Ventas;}

    float getTotalIngreso_Venta(){
    return totalIngreso_Venta;
    }

    bool leerVentaEnDisco(int);
};

    ///LEER EN DISCO
    bool Venta::leerVentaEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("VentasRT.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Venta),0);
    leyo=fread(this,sizeof (Venta),1,p);
    fclose(p);
    return leyo;
    }

    void Venta::listarVentas(){
    FILE *p;
    p=fopen("VentasRT.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    while(fread(this ,sizeof (Venta), 1,p)){
    mostrarVenta();
    cin.ignore();
    cout<<endl;

    }
    fclose(p);
    return;
    }


    void Venta::cargarVenta(){
    activo=false;
    cin.ignore();
    //cout<<"CODIGO DE VENTA:           ";///TIENE QUE SER UN AUTONUMERICO
    //cin.getline(codigo_Venta,20,'\n');
    cout<<"DNI VENDEDOR:              ";
    cin.getline(codigoVendedor_Venta,20,'\n');
    cout<<"DNI CLIENTE:               ";
    cin.getline(dni_Cliente_Venta,20,'\n');
    //fecha_Venta.cargarFecha();
    cout<<"NUMERO DE TIPOS DE PRENDA: ";
    cin>>cantidad_Ventas;
    /*for (int i=1;i<= cantidad_Ventas;i++ ){
        system("cls");
        cin.ignore();
        DetaVenta.cargar();
        DetaVenta.guardarEnDisco();
    }*/

    ///cout<<"INGRESO TOTAL:             ";
    ///cin>>totalIngreso_Venta;
    activo=true;
    }

    void Venta::mostrarVenta(){
    ///if(activo==true){
    cout<<"CODIGO DE VENTA:      "<<codigo_Venta<<endl;
    cout<<"VENDEDOR       :      "<<codigoVendedor_Venta<<endl;
    cout<<"DNI CLIENTE    :      "<<dni_Cliente_Venta<<endl;
    fecha_Venta.mostrarFecha();///FALTA COMPLETAR
    cout<<"INGRESO TOTAL  :      "<<totalIngreso_Venta<<endl;
    ///cout<<"BOOL: "<<activo<<endl;
    ///}
    }

    bool Venta::guardarVentaEnDisco(int posicion){
    FILE *p;
    bool grabo;
    if(posicion== -1){
        p=fopen("VentasRT.dat","ab");                       ///AHORA
        if(p==NULL)return false;
    }else{
        p=fopen("VentasRT.dat","rb+");
        if(p==NULL) return false;
        else fseek(p,posicion*sizeof (Venta),0);
    }
    grabo=fwrite(this,sizeof (Venta),1,p);
    fclose(p);
    return grabo;
    }


#endif // VENTA_H_INCLUDED
