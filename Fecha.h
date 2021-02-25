#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

///CLASE FECHA
class Fecha{
private:
    int dia, mes, anio;
    fecha();
public:
    void cargarFecha();
    void mostrarFecha();
    void mostrarFecha2();

    ///setts
    void setDia(int d){dia=d;};
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;};

    ///getss
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};


#endif // FECHA_H_INCLUDED
