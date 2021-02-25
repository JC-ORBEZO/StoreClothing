#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///STRUCT FECHINI
struct Fechini{
    int dia,mes,anio;
};

///FUNCIÓN FECHINI - FECHA DEL SISTEMA
Fechini hoy();


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
