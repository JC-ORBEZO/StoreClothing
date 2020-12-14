#ifndef FUNCMENUREPORTES_H_INCLUDED
#define FUNCMENUREPORTES_H_INCLUDED
///PUNTO 1: LISTAR INGRESOS POR MES
void nombreDeMes(char mes[12][30]){
strcpy(mes[0],"  ENERO      :  $ ");
strcpy(mes[1],"  FEBRERO    :  $ ");
strcpy(mes[2],"  MARZO      :  $ ");
strcpy(mes[3],"  ABRIL      :  $ ");
strcpy(mes[4],"  MAYO       :  $ ");
strcpy(mes[5],"  JUNIO      :  $ ");
strcpy(mes[6],"  JULIO      :  $ ");
strcpy(mes[7],"  AGOSTO     :  $ ");
strcpy(mes[8],"  SETIEMBRE  :  $ ");
strcpy(mes[9],"  OCTUBRE    :  $ ");
strcpy(mes[10],"  NOVIEMBRE  :  $ ");
strcpy(mes[11],"  DICIEMBRE  :  $ ");
}

void ingresoPorMes(){
char mes[12][30];
nombreDeMes(mes);
Venta Aux;
int ani;
cout<<"ANIO: ";
cin>>ani;
float Vec[12]={0};
FILE *p;
p=fopen("VentasNEW.dat","rb");
if(p==NULL)return;
while(fread(&Aux,sizeof(Venta),1,p)){
    if(ani==Aux.getFecha_Venta().getAnio()){
       Vec[Aux.getFecha_Venta().getMes()-1]+=Aux.getTotalIngreso_Venta();
    }
}
fclose(p);
cout<<"  INGRESOS POR MES "<<endl;
cout<<endl;
for (int i=0;i<12 ;i++ ){
    cout<<mes[i]<<Vec[i]<<endl;
}
}

///PUNTO 2: LISTAR INGRESOS ANUALES
void listarIngresosAnuales(){
cout<<" INGRESO ANUAL: ";
Venta Aux;
int an;
cout<<"";
cin>>an;
int pos=0;
float acum=0;
while(Aux.leerVentaEnDisco(pos++)){
    if(Aux.getFecha_Venta().getAnio()==an){
        acum+=Aux.getTotalIngreso_Venta();
    }
}
cout<<"INGRESO ACUMULADO "<<an<<":  $"<<acum<<endl;
}

///PUNTO 3: LISTAR VENTAS POR CÓDIGO
//oid (){
//
//

///PUNTO 4: LISTAR PRODUCTOS POR STOCK
void listarProductosSinStock(){
int limite;
cout<<"ESTABLECER STOCK LIMITE: ";
cin>>limite;
Producto Aux;
int pos=0;
while(Aux.leerProductoEnDisco(pos++)){
if(Aux.getStockProducto_P()<limite){
    Aux.mostrarProducto();
}
}

}

#endif // FUNCMENUREPORTES_H_INCLUDED
