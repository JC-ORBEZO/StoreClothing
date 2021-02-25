#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Funciones.h"

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
