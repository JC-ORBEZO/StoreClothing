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

    ///setts
    void setDia(int d){dia=d;};
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;};

    ///getss
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAnio(){return anio;};
};

void Fecha::cargarFecha(){
    cout<<"FECHA: "<<endl;
    cin>>dia;
    cin>>mes;
    cin>>anio;
}

void Fecha::mostrarFecha(){
    cout<<"FECHA          :      "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

#endif // FECHA_H_INCLUDED
