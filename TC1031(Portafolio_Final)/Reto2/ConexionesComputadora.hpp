//Trabajo colaborativo 
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646
#ifndef conexionescomputadora_h 
#define conexionescomputadora_h
#include <string>
#include <list>
#include "Conexion.hpp"
#include <iostream>

class ConexionesComputadora{
    public:
        ConexionesComputadora(std::string IP, std::string nombre){
            this->IP = IP;
            this->nombre = nombre; 
        };
        ~ConexionesComputadora() {}; 
        std::string IP;
        std::string nombre;
        std::list<Conexion> conexionesEntrantes; //leer de última a primera
        std::list<Conexion> conexionesSalientes; //leer de primera a última

        void insertarEnConexionesEntrantes(std::string IP, int puerto, std::string host){
            Conexion c(IP, puerto, host);
            conexionesEntrantes.push_front(c);
        }

        void insertarEnConexionesSalientes(std::string IP, int puerto, std::string host){
            Conexion c(IP, puerto, host); 
            conexionesSalientes.push_back(c);
        }

        std::string ultimaConexionEntrante(){
            return conexionesEntrantes.front().getIP(); 
        }
};
#endif