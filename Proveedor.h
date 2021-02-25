#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

/// CLASE PROVEEDOR
class Proveedor{
private:
    char cod_Proveedor[20];
    char nombre_Proveedor[20];
    char telefono_Proveedor[20];
    char direccion_Proveedor[20];
    bool activoProveedor;
public:
    void cargarProveedor();
    void mostrarProveedor();
    void mostrarProveedor2(int);
    bool guardarProveedorEnDisco(int= -1);
    bool leerEnDisco(int);
    int buscarPosicion(const char *codProv);
    void listarProveedoresID();
    ///gets
    const char *getCod_Proveedor(){
    return cod_Proveedor;
    };
    bool getActivoProveedor(){
    return activoProveedor;};
    ///sets
    void setActivoProveedor(bool a){
    activoProveedor=a;};
};


#endif // PROVEEDOR_H_INCLUDED
