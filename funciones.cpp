#include "funciones.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){
    vector<string> palabras;
    string line;

    ifstream infile(nombre_archivo);
    //Comprobamos que el archivo se pueda abrir correctamente
    if(infile.good() == false){
        cout<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }
    //Recorremos el archivo, leyendo linea por linea y, mientras la linea no este vacia,
    //se guardan las palabras en el vector palabras
    while(!infile.eof()){
        getline(infile, line);
        if(line != ""){
            palabras.push_back(line);
        } 
    }
    infile.close();

    return palabras;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
    bool validez_intento = false;
    //Mientras el intento tenga el mismo largo que la palabra secreta (5),
    //reccorremos el listado de palabras posibles para ver si el intento coincide con alguna
    if(intento.size() == palabra_secreta.size()){
        for(int i = 0; i < listado.size(); i++){
            if(intento == listado[i]){
                validez_intento = true;
            }
        }
    } 
    return validez_intento;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    vector<EstadoLetra> estado;

    //Recorremos letra por letra el string intento
    for(int i=0; i<intento.size(); i++){
        //Si el intento tiene la misma letra en la misma posicion que palabra_secreta
        //se guarda en estado LugarCorrecto
        if(intento[i]==palabra_secreta[i]){
            estado.push_back(EstadoLetra::LugarCorrecto);
        } else {
            bool encuentra_letra = false; //variable que usamos para determinar si se encuentra una letra
            //Si la letra no coincide en el mismo lugar, probamos si es que se encuentra en palabra_secreta
            for(int j=0; j<intento.size(); j++){
                //Comparamos la letra contra todas las letras de palabra_secreta, si la encuentra
                //encuentra_palabra cambia a true
                if(intento[i]==palabra_secreta[j]){
                    encuentra_letra = true;
                }
            }
            //Si encontro la letra en la palabra, guarda en el vector LugarIncorrecto,
            //si no la encontro (encuentra_palabra vale false) guarda NoPresente en el vector
            if (encuentra_letra == true){
                estado.push_back(EstadoLetra::LugarIncorrecto);
            } else {
                estado.push_back(EstadoLetra::NoPresente);
            }
        }
    }

    return estado;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string respuesta_string;
    
    //Recorre el vector y escribe en el string el caracter correspondiente a cada valor encontrado
    //en el vector
    for(int i = 0; i<respuesta.size(); i++){
        if(respuesta[i] == EstadoLetra::LugarCorrecto){
            respuesta_string.append("+");
        } else if(respuesta[i] == EstadoLetra::LugarIncorrecto){
            respuesta_string.append("-");
        } else {
            respuesta_string.append("X");
        }
    }

    return respuesta_string;
}