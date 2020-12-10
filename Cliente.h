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

 void Cliente::cargarCliente(){
    activo=false;
    cout<<"DNI CLIENTE:        ";
    cin.getline(dni_Cliente,30,'\n');
    cout<<"NOMBRE Y APELLIDO:  ";
    cin.getline(nombre_Cliente,30,'\n');
    cout<<"CORREO:             ";
    cin.getline(correo_Cliente,30,'\n');
    cout<<"TELEFONO:           ";
    cin.getline(telefono_Cliente,30,'\n');
    activo=true;
    }

    void Cliente::mostrarCliente(){
    if(activo==true){
            cin.ignore();
    cout<<"DNI CLIENTE:        "<<dni_Cliente<<endl;
    cout<<"NOMBRE Y APELLIDO:  "<<nombre_Cliente<<endl;
    cout<<"CORREO:             "<<correo_Cliente<<endl;
    cout<<"TELEFONO:           "<<telefono_Cliente<<endl;
    }
    }

    bool Cliente::guardarClienteEnDisco(int posicion){
    FILE *p;
    bool grabo;
    if(posicion==-1){
        p=fopen("ClientesNEW.dat","ab");
        if(p==NULL) return false;
    }else{
        p=fopen("ClientesNEW.dat","rb+");
        if(p==NULL) return false;
        else fseek(p,posicion*sizeof (Cliente),0);
    }
    grabo=fwrite(this,sizeof (Cliente),1,p);
    fclose(p);
    return grabo;
    }

    ///LEER EN DISCO
    bool Cliente::leerClienteEnDisco(int posicion){
    bool leyo;
    FILE *p;
    p=fopen("ClientesNEW.dat","rb");
    if(p==NULL){
        return false;
    }
    fseek(p,posicion*sizeof(Cliente),0);
    leyo=fread(this,sizeof (Cliente),1,p);
    fclose(p);
    return leyo;
    }

    ///BUSCAR POSCION CONST CHAR
    int Cliente::buscarPosicion(const char *dni){
    int pos=0;
    //char dni[30];
    //cout<<"INGRESE DNI CLIENTE: ";
    //cin.getline(dni,30,'\n');
    FILE *p;
    p=fopen("ClientesNEW.dat","rb");
    if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    while(fread(this,sizeof (Cliente),1,p)){
        if(strcmp(dni,dni_Cliente)==0){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
    }

    ///BUSCAR POSCION CHAR
    int Cliente::buscarPosicion2(char *dni){
    int pos=0;
    //char dni[30];
    //cout<<"INGRESE DNI CLIENTE: ";
    //cin.getline(dni,30,'\n');
    FILE *p;
    p=fopen("ClientesNEW.dat","rb");
    if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    while(fread(this,sizeof (Cliente),1,p)){
        if(dni==dni_Cliente){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -2;
    }
#endif // CLIENTE_H_INCLUDED
