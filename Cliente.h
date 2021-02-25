#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
class Cliente{
private:
    char dni_Cliente[30];
    char nombre_Cliente[30];
    char correo_Cliente[30];
    char telefono_Cliente[30];
    bool activo;
public:
    void cargarCliente();
    void mostrarCliente();
    void mostrarCliente2(int);
    bool guardarClienteEnDisco(int= -1);
    bool leerClienteEnDisco(int );
    int buscarPosicion(const char *);
    int buscarPosicion2( char *);
    ///gets
    const char *getDni_Cliente(){
    return dni_Cliente;
    }
    ///SETS
    void setActivo(bool act){
    activo=act;
    }
};


#endif // CLIENTE_H_INCLUDED
