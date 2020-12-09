#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
/// CLASE VENDEDOR
class Vendedor{
private:
    char codigo_Vendedor[20];
    char nombre_Vendedor[20];
    char dni_Vendedor[20];
    bool activo;
public:
    void cargarVendedor();
    void mostrarVendedor();
    bool guardarVendedorEnDisco(int= -1);
    bool leerVendedorEnDisco(int );
    int buscarPosicion(const char *);
    int buscarPosicion2( char *);
    ///gets
    const char *getCodigo_Vendedor(){
    return codigo_Vendedor;
    }
    ///SETS
    void setActivo(bool act){
    activo=act;
    }


};
    int Vendedor::buscarPosicion(const char *codVendedor){
    int pos=0;
    FILE *p;
    p=fopen("VendedoresRT.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Vendedor),1,p)){
    if(strcmp(codigo_Vendedor,codVendedor)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }

    int Vendedor::buscarPosicion2(char *codVendedor){
    int pos=0;
    FILE *p;
    p=fopen("VendedoresRT.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    return -1;
    }
    while(fread(this,sizeof (Vendedor),1,p)){
    if(strcmp(codigo_Vendedor,codVendedor)==0){
        fclose(p);
        return pos;
    } else{
        pos++;
    }
    }
    fclose(p);
    return -2;
    }


    void Vendedor::cargarVendedor(){
    activo=false;
    cout<<"CODIGO VENDEDOR: ";
    cin.getline(codigo_Vendedor,20,'\n');
    cout<<"NOMBRE Y APELLIDO: ";
    cin.getline(nombre_Vendedor,20,'\n');
    cout<<"DNI: ";
    cin.getline(dni_Vendedor,20,'\n');
    activo=true;
    }

    void Vendedor::mostrarVendedor(){
    if(activo==true){
    cin.ignore();
    cout<<"CODIGO VENDEDOR: "<<codigo_Vendedor<<endl;
    cout<<"NOMBRE Y APELLIDO: "<<nombre_Vendedor<<endl;
    cout<<"DNI: "<<dni_Vendedor<<endl;
    }
    }

    bool Vendedor::guardarVendedorEnDisco(int posicion){
    FILE *p;
    bool grabo;
    if(posicion==-1){
        p=fopen("VendedoresRT.dat","ab");
        if(p==NULL) return false;
    }else{
        p=fopen("VendedoresRT.dat","rb+");
        if(p==NULL) return false;
        else fseek(p,posicion*sizeof (Vendedor),0);
    }
    grabo=fwrite(this,sizeof (Vendedor),1,p);
    fclose(p);
    return grabo;
    }

    ///LEER EN DISCO
    bool Vendedor::leerVendedorEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("VendedorRT.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Vendedor),0);
    leyo=fread(this,sizeof (Vendedor),1,p);
    fclose(p);
    return leyo;
    }
#endif // VENDEDOR_H_INCLUDED
