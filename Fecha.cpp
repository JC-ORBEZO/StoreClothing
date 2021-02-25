#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "rlutil_c.h"

using namespace std;

#include "Fecha.h"

void Fecha::cargarFecha(){
    cout<<"FECHA: "<<endl;
    cin>>dia;
    cin>>mes;
    cin>>anio;
}

void Fecha::mostrarFecha2(){
    cout<<"FECHA          :      "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

void Fecha::mostrarFecha(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
