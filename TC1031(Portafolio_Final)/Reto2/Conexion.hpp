//Trabajo colaborativo 
//Lourdes Badillo, A01024232
//Eduardo Villalpando, A01023646
#ifndef conexion_h 
#define conexion_h
#include <string>

class Conexion{
    public:
        Conexion(std::string IP, int puerto, std::string host){
            this->IP = IP;
            this->puerto = puerto;
            this->host = host;
        }
        ~Conexion() {}; 
        std::string IP;
        int puerto;
        std::string host;

        std::string getIP(){
            return IP; 
        }
}; 

#endif