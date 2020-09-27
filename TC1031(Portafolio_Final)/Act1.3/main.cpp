//Trabajo colaborativo 
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646

#include <iostream>
#include <vector>
#include <map>
#include "reader.hpp"
using namespace std;

map<string, int> mails;
map<int, int> puertos;

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

// BúsquedaBinaria
int busquedaBinaria(vector<Registro>d, bool (*condicion)(Registro r), int inicio, int final){    
    int med = inicio + (final - inicio)/2;
    if(final<=inicio) return -1;
    if( condicion(d[med]) ) return med;
    int izq = busquedaBinaria(d, *condicion, inicio, med-1);
    if(izq!=-1) return izq; 
    int der = busquedaBinaria(d, *condicion, med+1, final);
    if(der!=-1) return der;
    return -1;
}

// ============================================================================
bool esPosterior(Registro a, Registro b){
    return (
        a.fecha.tm_mday > b.fecha.tm_mday &&
        a.fecha.tm_mon >= b.fecha.tm_mon &&
        a.fecha.tm_year >= b.fecha.tm_year
    );
}

bool perteneceA(Registro r){
    return(
        r.fuente_hostname == "jeffrey.reto.com" ||
        r.fuente_hostname == "betty.reto.com" ||
        r.fuente_hostname == "katherine.reto.com" ||
        r.fuente_hostname == "scott.reto.com" ||
        r.fuente_hostname == "benjamin.reto.com" ||
        r.fuente_hostname == "samuel.reto.com" ||
        r.fuente_hostname == "raymond.reto.com"
    );
}

bool seLlamaServer(Registro r){
    return r.fuente_hostname == "server.reto.com" || r.destino_hostname == "server.com";
}

bool esCorreo(Registro r){
    //El puerto 993 se usa para mail
    if(r.destino_puerto == 993){
        mails[r.destino_hostname]++; 
    }
    return false; 
}

bool esPuerto(Registro r){
    if(r.destino_puerto<1000 && r.destino_puerto>0){
        // Añadir al diccionario
        puertos[r.destino_puerto]++;
    }
    return false; 
}

string obtenerIPBase(vector<Registro> d){
    int i = busquedaSecuencial(d, [](Registro r){ return r.fuente_ip != "-";});
    string ip = d[i+1].fuente_ip;
    for(int i = 0; i<3; i++) ip.pop_back();
    ip.append(".0");
    return ip;
}

int main(void){
    Reader r; 
    vector <Registro> datos = r.readFile(); 
    //1. ¿Cuántos registros tiene tu archivo?
    cout<<"1\t¿Cuántos registros tiene tu archivo?"<<endl
        <<"El archivo tiene "<<datos.size()<<" registros"<<endl<<endl;
    
    //2.¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?
    cout<<"2\t ¿Cuántos récords hay del segundo día registrado? ¿Qué día es?"<<endl;
    int primerDiaCount = busquedaSecuencial(datos, *esPosterior, datos[0]);
    int segundoDiaCount = busquedaSecuencial(datos, *esPosterior, datos[primerDiaCount]) - primerDiaCount;
    
    cout<<"En el primer día (";
    datos[0].printDate();
    cout<<") hubieron "<<primerDiaCount<<" datos"<<endl;
    cout<<"En el segundo día (";
    datos[segundoDiaCount].printDate();
    cout<<") hubieron "<<segundoDiaCount<<" datos"<<endl<<endl;

    //3. ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond?
    cout<<"3\t¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond?"<<endl;
    int perteneceCount = busquedaSecuencial(datos, *perteneceA);
    cout<<( perteneceCount==0 ? "No." : "Sí." )<<endl;

    //4. ¿Cuál es la dirección de la red interna de la compañía?
    // Sustituir para usar comparadores y búsqueda secuencial. DONE
    cout<<"4\t¿Cuál es la dirección de la red interna de la compañía?"<<endl;
    cout<<"La dirección de la red interna es: "<<obtenerIPBase(datos)<<endl;
    
    //5. ¿Alguna computadora se llama server.reto.com?
    cout<<"5\t¿Alguna computadora se llama server.reto.com?"<<endl;
    int serverCount = busquedaSecuencial(datos, *seLlamaServer);
    cout<<( serverCount<0 ? "No." : "Sí." )<<endl;

    //6. ¿Qué servicio de mail utilizan? 
    cout<<"6\t¿Qué servicio de mail utilizan?"<<endl;
    int mailCount = busquedaSecuencial(datos, *esCorreo);
    std::cout << "Mail" << "\t\t" << "Cantidad"<< "\n";
    for (const auto& x : mails ) {
        std::cout << x.first << " \t" << x.second << "\n";
    }

    //7. Considerando solamento los puertos destino: 
    //¿Qué puertos abajo del 1000 se están usando? Lista los puertos. 
    cout<<"7\t¿Qué puertos abajo del 1000 se están usando?"<<endl;
    int puertosCount = busquedaSecuencial(datos, *esPuerto);
    std::cout << "Puerto" << " \t" << "Cantidad"<< "\n";
    for (const auto& x : puertos ) {
        std::cout << x.first << " \t" << x.second << "\n";
    }

    return 0;
}
