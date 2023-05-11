# taller1-TD3

Este es el primer taller en C++ de la Materia Tecnología Digital III: Algoritmos y Estructuras de Datos.

**Instrucciones dadas por catedra**

Reglas del juego:
El objetivo del juego es adivinar una palabra secreta de 5 letras en español. Para eso se tienen 6 oportunidades para intentar ingresar la palabra correcta.
Luego de cada intento el juego indica, por cada letra de la palabra ingresada, si la palabra secreta contiene esa letra en esa posición, si la palabra secreta contiene esa letra pero en otra posición, o si la palabra secreta no contiene esa letra.
Con esta información se puede realizar un nuevo intento hasta o bien adivinar la palabra secreta o bien agotar los 6 intentos.
Proyecto C++ adjunto:

funciones.cpp: archivo con distintas funcionalidades para implementar el juego.

funciones.h: encabezado que declara las funciones de funciones.cpp y tipos de datos necesarios para la implementación.

wordle.cpp: este archivo contiene la función main() que debe utilizar las funciones declaradas en funciones.h para implementar el juego interactivo.

listado.txt: listado de palabras en español de cinco letras que se debe utilizar como diccionario del juego. Por simplicidad sólo vamos a utilizar palabras sin letras repetidas, sin tildes y sin mayúsculas.

CMakeLists.txt: proyecto para compilar usando CMake (es necesario en caso de que quieran ejecutar los casos de test)
tests/: directorio que contiene casos de test escritos por la cátedra para que verifiquen sus implementaciones. Utiliza el framework Google Test (gtest).

Consigna:

Deben implementar todas las funciones de funciones.cpp. En la implementación de cada función deben escribir comentarios que ayuden a entender la forma en que está resuelta.

cargar_listado toma el nombre de un archivo que contiene una palabra por línea y devuelve un vector de strings con todas las palabras tal como están en el archivo.

intento_valido toma un intento, una palabra secreta y un listado de palabras e indica si el intento es legal o no. Un intento es legal si tiene la misma longitud que la palabra secreta y si es una palabra reconocida en el listado de palabras.

evaluar_intento toma un intento y una palabra secreta, y devuelve un vector con la respuesta para cada una de las letras del intento. Una letra del intento puede estar en el LugarCorrect si la palabra secreta tiene esa misma letra en esa posición, puede estar en un LugarIncorrecto si la palabra secreta contiene esa letra pero en otra posición, o puede estar NoPresente si la palabra secreta no contiene esa letra.

Por ejemplo: si la palabra secreta es "bolsa" y el intento es "aviso", se espera que esta función devuelva el vector {LugarIncorrecto, NoPresente, NoPresente, LugarCorrecto, LugarIncorrecto}.

respuesta_en_string toma el vector de EstadoLetra que devuelve evaluar_intento y devuelve un string que se puede imprimir por pantalla para indicar esa respuesta al usuario. Se espera que LugarCorrecto se indique con el caracter "+", LugarIncorrecto con el caracter "-", y NoPresente con el caracter "X".

Por ejemplo: si el vector en entrada es {LugarIncorrecto, NoPresente, NoPresente, LugarCorrecto, LugarIncorrecto} se espera que el string de salida sea "-XX+-".

Deben implementar la función main() de wordle.cpp:

Aquí se debe implementar la parte interactiva del juego utilizando las funciones de funciones.cpp.
El juego debe cargar el listado de palabras del archivo "listado.txt" y, en cada ejecución, debe elegir una de estas palabras al azar para utilizar como palabra secreta. Para obtener un numero pseudo-aleatorio pueden utilizar la función rand() de la biblioteca de C: https://en.cppreference.com/w/cpp/numeric/random/rand.
Luego se le debe pedir al usuario que haga un intento para adivinar la palabra secreta.
En caso de que el intento sea válido se debe evaluar el intento y darle la respuesta al usuario por pantalla. Esto le resta un intento al usuario para adivinar la palabra.
En caso de que el intento no sea válido (es decir, no sea legal) se debe indicar por pantalla que el intento no es valido e invitar al usuario escribir un nuevo intento. En este caso no se le resta al usuario una oportunidad.
En caso de que el usuario adivine la palabra el juego termina y se debe indicar por pantalla que el usuario adivinó.
En caso de que se agoten los cinco intentos el juego termina y se debe indicar por pantalla que el número de intentos se agotó.

Tests:

El proyecto en CMakeLists.txt genera dos ejecutables: wordle y tests.
El primero es el juego interactivo y el segundo es la suite de tests.
Su implementación debe pasar todos los tests satisfactoriamente para poder aprobar.
Pueden ver los casos de test en el archivo tests/tests.cpp.
