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

///LISTAR PRODUCTOS
    void Proveedor::listarProveedoresID(){
    FILE *p;
    p=fopen("Proveedores.dat","rb");

    if(p==NULL){
    cout<<"ERROR EN EL ARCHIVO"<<endl;
    return;
    }
    while(fread(this ,sizeof (Proveedor), 1,p)){
    mostrarProveedor();
    cout<<endl;
    }
    fclose(p);
    return;
    }

///BUSCAR POSICION
    int Proveedor::buscarPosicion(const char *codProv){
    int pos=0;
    FILE *p;
    p=fopen("Proveedores.dat","rb+");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Proveedor),1,p)){
    if(strcmp(cod_Proveedor,codProv)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

void Proveedor::cargarProveedor(){
cin.ignore();
activoProveedor=false;
cout<<"CODIGO PROVEEDOR: ";
cin.getline(cod_Proveedor,20,'\n');
cout<<"NOMBRE PROVEEDOR: ";
cin.getline(nombre_Proveedor,20,'\n');
cout<<"TELEFONO: ";
cin.getline(telefono_Proveedor,20,'\n');
cout<<"DIRECCION: ";
cin.getline(direccion_Proveedor,20,'\n');
activoProveedor=true;
}

void Proveedor::mostrarProveedor(){
if(activoProveedor==true){
cout<<"CODIGO PROVEEDOR:   "<<cod_Proveedor<<endl;
cout<<"NOMBRE PROVEEDOR:   "<<nombre_Proveedor<<endl;
cout<<"TELEFONO:           "<<telefono_Proveedor<<endl;
cout<<"DIRECCION:          "<<direccion_Proveedor<<endl;
cout<<activoProveedor<<endl;
}
}

bool Proveedor::guardarProveedorEnDisco(int posicion){
FILE *p;
bool grabo;
if(posicion==-1){
    p=fopen("Proveedores.dat","ab");
    if(p==NULL) return false;
}else{
    p=fopen("Proveedores.dat","rb+");
    if(p==NULL) return false;
    else fseek(p,posicion*sizeof (Proveedor),0);
}
grabo=fwrite(this,sizeof (Proveedor),1,p);
fclose(p);
return grabo;
}

#endif // PROVEEDOR_H_INCLUDED
