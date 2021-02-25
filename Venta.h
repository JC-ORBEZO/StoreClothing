#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include "DetalleVenta.h"
#include "Funciones.h"
///CLASE VENTAS
class Venta{
private:
    int codigo_Venta;/// AUTONUMERICO
    char codigoVendedor_Venta[20];
    char dni_Cliente_Venta[20];
    Fecha fecha_Venta;
    int cantidad_Ventas;        /// EXTRA PARA ACOPLAR CANTIDAD DE DETALLES DE VENTA
    DetalleVenta DetaVenta;   /// EXTRA PARA ACOPLAR DETALLE VENTAS
    float totalIngreso_Venta;
    bool activo;
public:
    void cargarVenta();
    void mostrarVenta();
    void mostrarVenta2(int );
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




#endif // VENTA_H_INCLUDED
