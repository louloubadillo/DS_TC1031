
//Este programa asocia direcciones IP de entrada y salida a una computadora.
//Trabajo colaborativo por:
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646
//13/10/2020

#include <iostream>
#include <vector>
#include <map>
#include "reader.hpp"
#include "ConexionesComputadora.hpp"
using namespace std;


// Imprimir vectores
void print_vector(vector<Registro> arr){
    for (int i = 0; i < arr.size(); i++) arr[i].print();
    cout << endl;
};

// Búsqueda secuencial
int busquedaSecuencial( vector<Registro> d, bool (*condicion)(Registro r) ){
    for(int i = 0; i<d.size(); i++){
        if( condicion(d[i]) ) return i;
    }
    return -1;
}
// Busqueda secuencial (sobrecarga)
int busquedaSecuencial( vector<Registro> d, bool (*condicion)(Registro a, Registro b), Registro r ){
    for(int i = 0; i<d.size(); i++){
        if( condicion(d[i], r) ) return i;
    }
    return -1;
}

string IPUsuario;

bool esIP(Registro r){
    return r.fuente_ip == IPUsuario;
}

string obtenerIPBase(vector<Registro> d){
    int i = busquedaSecuencial(d, [](Registro r){ return r.fuente_ip != "-";});
    string ip = d[i+1].fuente_ip;
    for(int i = 0; i<3; i++) ip.pop_back();
    ip.append(".0");
    return ip;
}
string obtenerIPUsuario(string base, int usuario){
    string ipUsuario = base;
    ipUsuario.pop_back();
    ipUsuario.append( std::to_string(usuario) );
    return ipUsuario;
}

int askNumber(vector <Registro> datos){
    string IPBase = obtenerIPBase(datos);
    int direccionUsuario;
    while(direccionUsuario < 1 || direccionUsuario > 150){
        cout<<"Ingresa un numero > \t";
        cin>>direccionUsuario;
    }
    IPUsuario = obtenerIPUsuario(IPBase, direccionUsuario);
    int usuarioIndex = busquedaSecuencial(datos, *esIP);
    if (usuarioIndex == -1) return askNumber(datos);
    return usuarioIndex; 
}

void llenar(vector <Registro> datos, ConexionesComputadora &conexionInput){
    for(int i=0; i<datos.size(); i++){
        if( datos[i].destino_ip == conexionInput.IP ){
            conexionInput.insertarEnConexionesEntrantes(
                datos[i].fuente_ip, 
                datos[i].fuente_puerto,
                datos[i].fuente_hostname
            );
        } 

        if( datos[i].fuente_ip == conexionInput.IP ){
            conexionInput.insertarEnConexionesSalientes(
                datos[i].destino_ip, 
                datos[i].destino_puerto,
                datos[i].destino_hostname
            );
        } 
    }
}

bool esInterna(string IPBase, string IPInput){
    // 172.26.89.0 == 172.26.89.142
    for(int i=0; i<10; i++){
        if( IPBase[i] != IPInput[i] ) return false;
    }
    return true; 
}

bool ThreeInaRow(ConexionesComputadora &conexionInput){
    // [ ... x x x ...  ]
    auto Ptr1 = conexionInput.conexionesSalientes.begin();
    auto Ptr2 = std::next(Ptr1, 1);
    auto Ptr3 = std::next(Ptr2, 1);
    
    for(int i=0; i<conexionInput.conexionesSalientes.size() - 3; i++){
        if(Ptr1->getIP() == Ptr2->getIP() &&  Ptr2->getIP() == Ptr3->getIP()) return true;

        Ptr1 = std::next(Ptr1, 1);
        Ptr2 = std::next(Ptr2, 1);
        Ptr3 = std::next(Ptr3, 1);
    }
    return false;
}

int main(void){
    Reader r; 
    vector <Registro> datos = r.readFile(); 

    string IPBase = obtenerIPBase(datos); 

    int usuarioIndex = askNumber(datos);
    string nombreUsuario = datos[usuarioIndex].fuente_hostname;
    ConexionesComputadora conexionUsuario = ConexionesComputadora(IPUsuario, nombreUsuario); 
    cout <<"La IP interna correspondiente es: " <<conexionUsuario.IP << endl; 
    llenar(datos, conexionUsuario);
    ConexionesComputadora computadoraConocida = ConexionesComputadora("172.26.89.142", "janet.reto.com");
    llenar(datos, computadoraConocida);
    //¿Qué dirección ip estas usando?
    cout<<"¿Qué dirección IP estás usando?"<<endl;
    cout<<"\t Estoy usando la dirección ip "<<computadoraConocida.IP<<endl;
    //¿Cuál fue la ip de la última conexión que recibió esta computadora? ¿Es interna o externa?
    cout << "¿Cuál fue la ip de la última conexión que recibió esta computadora?" << endl; 
    string ultimaConexion = computadoraConocida.ultimaConexionEntrante(); 
    cout<<"\t La ip de la última conexión que recibió esta computadora es: "<< ultimaConexion <<endl;
    cout << "¿Es interna o externa?" << endl;
    cout << "\t" << (esInterna(IPBase, ultimaConexion) ? "Es interna" : "Es externa") << endl;
    //¿Cuántas conexiones entrantes tiene esta computadora?
    cout << " ¿Cuántas conexiones entrantes tiene esta computadora?" << endl; 
    cout << "\t Esta computadora tiene " << computadoraConocida.conexionesEntrantes.size() << " conexiones entrantes" << endl;
    //¿Cuántas conexiones salientes tiene esta computadora?
    cout << "¿Cuántas conexiones salientes tiene esta computadora?" << endl; 
    cout << "\t Esta computadora tiene "<<computadoraConocida.conexionesSalientes.size() << " conexiones salientes" << endl;
    //Extra: ¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web?
    cout << "¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web?" << endl; 
    cout << "\t" << (ThreeInaRow(computadoraConocida) ? "Sí tiene 3 conexiones seguidas" : "No tiene 3 conexiones seguidas") << endl;
    return 0;
}
