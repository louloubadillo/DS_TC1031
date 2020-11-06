// Referencia de código: https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/
// Referencia de código: https://www.youtube.com/watch?v=wRj9PZ2wyZI
//Trabajo colaborativo 
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646
#ifndef reader_h 
#define reader_h
#include <string>
#include "registro.hpp"
#include <fstream>
#include <vector>
using namespace std;
class Reader{
    public: 
    Reader() = default; 
    ~Reader() = default;
    vector<Registro> readFile(){
        ifstream ip("equipo0.csv");
        vector<Registro> registros; 
        
        if(!ip.is_open()){
           std::cout << "Error: File Open" << endl; 
        }

        string fecha; 
        string hora; 
        string fuente_ip; 
        string fuente_puerto; 
        string fuente_hostname; 
        string destino_ip; 
        string destino_puerto; 
        string destino_hostname;

        while(ip.good()){
            getline(ip, fecha, ','); 
            getline(ip, hora, ',');
            getline(ip, fuente_ip, ',');
            getline(ip, fuente_puerto, ',');
            getline(ip, fuente_hostname, ',');
            getline(ip, destino_ip, ',');
            getline(ip, destino_puerto, ',');
            getline(ip, destino_hostname, '\n');
             registros.push_back(Registro(fecha,hora, fuente_ip, fuente_puerto, fuente_hostname, destino_ip, destino_puerto, destino_hostname)); 
        }

        ip.close(); 
        return registros; 
    }
};

#endif