#include "funciones.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    //Carga el listado de palabras listado.txt
    vector<string> listado_palabras = cargar_listado("../listado.txt");
    
    //Selecciona al azar una palabra del listado
    srand(time(0));
    string palabra_secreta = listado_palabras[(rand() % listado_palabras.size())];
    
    int intentos_disponibles = 6;
    string intento;
    bool todo_correcto = true; //variable que se usa mas adelante para comprobar si todo el intento es correcto o no
    
    cout << "Bienvenido a Wordle! Tiene 6 intentos para adivinar la palabra secreta" << endl;
    
    while(intentos_disponibles != 0){
        //Mientras se tengan intentos disponibles se ingresa una palabra
        cout << "Ingrese una palabra de 5 letras:" << endl;
        cin >> intento;

        //Verifica si el intento es valido
        if(intento_valido(intento, palabra_secreta, listado_palabras) == false){
            //Si no es valido imprime en terminal que no es valido y vuelve a ejecutarse el ciclo
            cout << "El intento no es valido" << endl;
        } else {
            //Si el intento es valido, se evalua el intento, se pasa a string lo que se obtiene de evaluar
            //y se muestra en la terminal, decrementando la cantidad de intentos disponibles en 1
            vector<EstadoLetra> intento_evaluado = evaluar_intento(intento, palabra_secreta);
            string intento_evaluado_string = respuesta_en_string(intento_evaluado);
            cout << intento_evaluado_string << endl;
            intentos_disponibles--;

            todo_correcto = true;
            for(int i=0; i<intento_evaluado.size(); i++){
                //Recorre el vector con los estados de las letras y si encuentra una 
                //que no este en la posicion correcta, cambia la variable todo_correcto a false
                if(intento_evaluado[i] != EstadoLetra::LugarCorrecto){
                    todo_correcto = false;
                }
            }
            if(todo_correcto == true){
                //Si toda la palabra es correcta, intentos_disponibles pasa a 0 para que no continue el ciclo
                cout << "Felicitaciones! Ha adivinado la palabra en " << 6 - intentos_disponibles << " intentos" << endl;
                intentos_disponibles = 0; //hace que termine el ciclo
            }
        } 
    }
    if(todo_correcto == false){
        //Si al salir del ciclo por no tener más intentos disponibles todo_correcto = false
        //no se encontro la palabra correcta
        cout << "Se ha quedado sin intentos, la palabra correcta era: " << palabra_secreta << endl;
    }


}