#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///STRUCT FECHINI
struct Fechini{
    int dia,mes,anio;
};

///FUNCIÓN FECHINI - FECHA DEL SISTEMA
Fechini hoy(){
    time_t t;
    t=time(NULL);
    struct tm *f;
    f=localtime(&t);
    Fechini aux;
    aux.anio=f->tm_year + 1900;
    aux.mes=f->tm_mon + 1;
    aux.dia=f->tm_mday;
    return aux;
}

/*///CONTAR VENTAS EN ARCHIVO PARA EL AUTONUMERICO
int contadorVentas(){
int cont=0;
FILE *p;
p=fopen("Ventas.dat","rb");

fseek(p,0,SEEK_END);
cont=ftell(p);
fclose(p);
cont=cont/sizeof(Venta);
return cont;
}*/


#endif // FUNCIONES_H_INCLUDED
