#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
/// CLASE VENDEDOR
class Vendedor{
private:
    char codigo_Vendedor[20];
    char nombre_Vendedor[20];
    char dni_Vendedor[20];
    char claveAcceso[20];
    bool activo;
public:
    void cargarVendedor();
    void mostrarVendedor();
    void mostrarVendedor2(int b);
    bool guardarVendedorEnDisco(int= -1);
    bool leerVendedorEnDisco(int );
    int buscarPosicion(const char *);
    int buscarPosicion2( char *);
    ///gets
    const char *getCodigo_Vendedor(){
    return codigo_Vendedor;
    }
    const char *getClaveAcceso(){
    return claveAcceso;
    }

    ///SETS
    void setActivo(bool act){
    activo=act;
    }


};

#endif // VENDEDOR_H_INCLUDED
