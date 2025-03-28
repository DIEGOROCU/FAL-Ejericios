//DIEGO RODRIGUEZ CUBERO FAL-DG30 - PROBLEMA 3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

// Estructura para la puntuacion maxima
struct tPuntuacionMaxima{
  int punt;
  int cant = 1;
};

void resuelveCaso() {

    // Leemos la primera puntuacion, que sera la maxima por ahora al ser la unica
    tPuntuacionMaxima puntuacion;
    std::cin >> puntuacion.punt;

    // Leemos la siguiente puntuacion
    int aux;
    std::cin >> aux;
    
    // Repetimos mientras la siguiente puntuacion no sea 0
    while (aux != 0){
        
        // Si la puntuacion es mayor que la maxima actual, la guardamos y establecemos la cantidad a 1
        if (aux > puntuacion.punt){
            puntuacion.punt = aux;
            puntuacion.cant = 1;
        }
        // Si la puntuacion es igual a la maxima actual, aumentamos la cantidad en 1
        else if (aux == puntuacion.punt){
            puntuacion.cant++;
        }
        
        // Leemos la siguiente puntuacion
        std::cin >> aux;
        
    }

    // Devolvemos la puntuacion maxima y la cantidad de veces que se ha repetido
    std::cout << puntuacion.punt << " " << puntuacion.cant << '\n';
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}