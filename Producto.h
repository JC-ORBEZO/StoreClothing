#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
/// CLASE PRODUCTO
class Producto{
private:
    char codProducto_P[20];
    char nombre_Producto_P[20];
    char codProveedor_P[20];
    float precioVentaProducto_P;
    float precioCompraProducto_P;
    int stockProducto_P;
    char talle_Producto[5];
    bool activo;
public:
    Producto();
    void listarProductoXid();
    void listarProductosID();
    int buscarPosicion(const char *);
    int buscarPosicion2(char *);
    void modificarNombreProducto();///
    void AumentarStock(int s){
    stockProducto_P+=s;
    };
    void disminuirStock(int cantidad){
    stockProducto_P=stockProducto_P-cantidad;
    };

    ///setters
    void setCodProducto_P(char *);
    void setNombre_Producto_P(char *);
    void setCodProveedor_P(char *);
    void setPrecioVentaProducto_P(float);
    void setPrecioCompraProducto_P(float);
    void setStockProducto_P(int);
    void setTalle_Producto(char *);
         /// void setActivo();

    ///getters
    const char *getCodProducto_P(){
    return codProducto_P;
    }
    char getNombre_Producto_P();
    const char *getCodProveedor_P(){
    return codProveedor_P;
    }
    float getPrecioVentaProducto_P();
    float getPrecioCompraProducto_P();
    int getStockProducto_P();
    char getTalle_Producto();

    void cargarProducto();
    void mostrarProducto();
    void mostrarProducto2(int b);//
    bool guardarProductoEnDisco(int = -1);
    bool leerProductoEnDisco(int);
};


#endif // PRODUCTO_H_INCLUDED
