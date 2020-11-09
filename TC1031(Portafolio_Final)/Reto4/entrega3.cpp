
//Este programa es la tercera parte del reto de la materia, para el cual implementamos conjuntos y diccionarios.
//Trabajo colaborativo por:
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646
//9/11/2020

#include <iostream>
#include <vector>
#include <map>
#include "reader.hpp"
#include "ConexionesComputadora.hpp"
#include <set>
#include <cwctype> 
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


void agregarNoRetoASet(set<string> s, vector<Registro> datos){
    for(int i=0; i<5000; i++){
        if(datos[i].fuente_hostname.find(".reto.com") || datos[i].fuente_hostname.find("-") ){
            s.insert(datos[i].fuente_hostname); 
        }
    }
}

void llenarComputadoras(map<string, ConexionesComputadora> &computadoras, vector<Registro> datos){
    // throwback a nuestro debugging de una hora, porque no estábamos editando el map original :)
    for(int i=0; i<6000; i++){ //Cambiar a datos.size()
        ConexionesComputadora c(datos[i].fuente_ip, datos[i].fuente_hostname);
        c.llenar(datos);
        computadoras.insert(pair<string,ConexionesComputadora>(datos[i].fuente_ip,c));
    }
}

void agregarNoRetoASetyLlenarComputadoras(set<string> s, map<string, ConexionesComputadora> &computadoras, vector<Registro> datos){
    for(size_t i=0; i<datos.size(); i++){
        if(datos[i].fuente_hostname.find(".reto.com") || datos[i].fuente_hostname.find("-") ){
            s.insert(datos[i].fuente_hostname); 
        }
        // Correr si la IP origen no está en el map
        if( datos[i].fuente_ip != "-" && computadoras.find(datos[i].fuente_ip) == computadoras.end() ){
            ConexionesComputadora c(datos[i].fuente_ip, datos[i].fuente_hostname);
            c.llenar(datos);
            computadoras.insert(pair<string,ConexionesComputadora>(datos[i].fuente_ip,c));
        }
        // Correr si la IP destino no está en el map
        if( datos[i].destino_ip != "-" && computadoras.find(datos[i].destino_ip) == computadoras.end()){
            ConexionesComputadora c(datos[i].destino_ip, datos[i].destino_hostname);
            c.llenar(datos);
            computadoras.insert(pair<string,ConexionesComputadora>(datos[i].destino_ip,c));
        }
    }
}

bool esAnomalo(string nombre){
    // largo
    // caracteres alfanumericos
    if (nombre.size() >= 20) return true;
    for(int i=0; i<nombre.size(); i++){
        if(isalpha(nombre[i]) == false && nombre[i] != '.' && nombre[i] != '-'&&  nombre[i] != '/' ){
            return true;  
        }
    }
    return false; 
}

string encontrarAnomalos(map<string, ConexionesComputadora> computadoras){
    map<string, ConexionesComputadora>::iterator it;
    for(it = computadoras.begin(); it != computadoras.end(); it++){
        if( esAnomalo( it->second.nombre ) ) return it->first;
    }
    return "";
}


int computadorasConConexionesEntrantes(map<string, ConexionesComputadora> computadoras){ 
    int n = 0;
    map<string, ConexionesComputadora>::iterator it;
    for(it = computadoras.begin(); it != computadoras.end(); it++ ){
        if(it->second.nombre.find("reto.com") != string::npos && it->second.conexionesEntrantes.size() >= 1) n++;
    }
    return n;
} 

set<string> obtenerIPsEntrantes(map<string, ConexionesComputadora> computadoras) {
    /**
     * - for computadora in computadoras
     * -    si computadora.IP != server.reto.com
     *          iterar por conexiones entrantes
     *              si conexionEntrante.puerto != 67
     *                  agregar IP al set (para que no se repita :))
     * regresar set
     * Los mensajes DHCP utilizan el puerto 67 (UDP) como puerto del servidor
    */
    set<string> ipsUnicas;

    map<string, ConexionesComputadora>::iterator it;
    int n = 0;
    for(it = computadoras.begin(); it != computadoras.end(); it++ ){
        if( it->second.nombre.find(".reto.com") == string::npos /*no lo encontró*/ ){
            n++;
            // Convertir a vector para poder acceder los índices de manera más fácil ;D
            vector<Conexion> conexionesV{begin(it->second.conexionesEntrantes), end(it->second.conexionesEntrantes) };
            set<string> nombresPorComputadoraUnicos;
            for(int i=0; i< conexionesV.size(); i++ ){
                if ( conexionesV[i].puerto != 67 ){
                    nombresPorComputadoraUnicos.insert(conexionesV[i].host);
                    ipsUnicas.insert( conexionesV[i].IP );
                }
            }
        }
    }

   return ipsUnicas; 
}



int main(void){
    Reader r; 
    vector <Registro> datos = r.readFile(); 
    // Cree un conjunto de strings. En este debes agregar los nombres de los dominios/computadoras que no pertenezcan al dominio reto.com.
    set<string> notReto; 
    // -- agregarNoRetoASet(notReto, datos);
    // Crea una diccionario de pares <string,ConexionesComputadora> usando la clase creada en el reto pasado. 
    // Este diccionario debe ser llenado con todas las ips en los datos. 
    // Por cada una, es necesario registrar todas las conexiones que hayan salido desde esta ip o hayan sido recibidas por la misma.
    map<string, ConexionesComputadora> computadoras; 
    // -- llenarComputadoras(computadoras, datos); 

    agregarNoRetoASetyLlenarComputadoras(notReto, computadoras, datos);
    cout << "0. Hay "<<computadoras.size()<<" computadoras"<<endl;


    //Hay algún nombre de dominio que sea anómalo (Esto puede ser con inspección visual).
    cout << "1. ¿Hay algún nombre de dominio que sea anómalo?" << endl; //ds19smmrn47jp3osf6x4.com
    cout <<"\t"<<(encontrarAnomalos(computadoras)!="" ? "Sí." : "No.") << endl; 
    
    // De los nombres de dominio encontrados en el paso anterior, ¿Cuál es su ip? 
    // ¿Cómo determinarías esta información de la manera más eficiente en complejidad temporal?
    cout << "2. ¿Cuál es su IP? ¿Cómo determinarías esta información de la manera más eficiente en complejidad temporal?" << endl;
    string ipAnomala = encontrarAnomalos(computadoras); 
    cout << "\tLa IP es " << ipAnomala << endl;
    
    cout << "\tCon una inspección visual identificamos: ds19smmrn47jp3osf6x4.com" << endl; 
    cout << "\tHicimos una función prototipo de cómo se podrían encontrar dominios anómalos: encontrarAnomalos(datos)" << endl; 
    cout << "\tPara esto usamos como parámetros el largo del dominio y si contiene caracteres no alfanuméricos" << endl; 
    cout << "\tUna implementación eficiente podría ser tener un algoritmo de machine learning, que vaya aprendiendo qué dominios son anómalos y los detecte en una complejidad O(1)" << endl;
    
    //De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante. 
    //(Recuerda que ya tienes la dirección de la red y el último octeto puede tener computadoras del .1 al .254). 
    //Imprime la cantidad de computadoras.
    cout << "3. De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante." << endl; 
    cout << "\t" << computadorasConConexionesEntrantes(computadoras) << " computadoras de la red interna con al menos una conexion entrante" << endl;

    //Toma algunas computadoras que no sean server.reto.com o el servidor dhcp. Pueden ser entre 5 y 150. Obtén las ip únicas de las conexiones entrantes.
    cout << "4. Toma algunas computadoras que no sean server.reto.com o el servidor dhcp. Pueden ser entre 5 y 150. Obtén las ip únicas de las conexiones entrantes." << endl;
    set<string> conexiones = obtenerIPsEntrantes(computadoras);
    
    for (auto it = conexiones.begin(); it != conexiones.end(); ++it){
        cout << '\t' << *it << endl;
    }
    
    //Considerando el resultado de las preguntas 3 y 4, ¿Qué crees que esté ocurriendo en esta red? (Pregunta sin código)
    cout << "5. Considerando el resultado de las preguntas 3 y 4, ¿Qué crees que esté ocurriendo en esta red? (Pregunta sin código)"<<endl;
    cout << "\t32 computadoras internas tienen conexiones entrantes. Esto significa que computadoras externas están intentando acceder a la información. "<<endl;
    cout << "\tDe las conexiones entrantes, puede identificarse que existe solo una conexión al dominio anómalo"<<endl;

    //Para las ips encontradas en el paso anterior, determina si se han comunicado con los datos encontrados en la pregunta 1.
    // Iterar conexiones entrantes de ip anomala;
    // Ver si alguna conexión pertnece a conexiones
    list<Conexion> conexionesEntrantesAIPAnomala = computadoras[ipAnomala].conexionesEntrantes;
    map<string, int> culpable;
    for (auto it = conexionesEntrantesAIPAnomala.begin(); it != conexionesEntrantesAIPAnomala.end(); ++it){
        culpable[ it->host ] ++;
    }
    for (auto it = culpable.begin(); it != culpable.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    cout << "(Extra):  En caso de que hayas encontrado que las computadoras del paso 1 y 4 se comunican, determina en qué fecha ocurre la primera comunicación entre estas 2 y qué protocolo se usó."<<endl;
    cout << "\tLa computadora de Jennifer se infectó el: "; 
    conexionesEntrantesAIPAnomala.back().imprimirFecha();
    cout << endl; 
    cout << "\tPuerto: " << conexionesEntrantesAIPAnomala.back().puerto << endl;
    cout << endl;


    return 0;
}
