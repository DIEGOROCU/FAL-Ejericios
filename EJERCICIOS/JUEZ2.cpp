// Diego Rodriguez Cubero DG30 FAL

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

bool sonDalton(vector<int>& dalton){
    // Declaramos dos variables booleanas para saber si la secuencia es creciente o decreciente
    bool creciente = true;
    bool decreciente = true;
    // Recorremos el vector de daltons para comprobar si es creciente o decreciente comparando cada elemento con el siguiente
    for (int i = 0; i < dalton.size() - 1; i++){
        if (dalton[i] >= dalton[i + 1]){
            creciente = false;
        }
        if (dalton[i] <= dalton[i + 1]){
            decreciente = false;
        }
    }
    // Devolvemos el resultado de la comparación
    return creciente || decreciente;
}

bool resuelveCaso() {
    
    // Leemos la cantidad de daltons
    int cantidadDalton;
    std::cin >> cantidadDalton;

    // Precondicion: {cantidadDalton > 0}
    // Revisamos que haya al menos un dalton
    if (cantidadDalton == 0){
        return false;
    }
 
    // Leemos los daltons
    vector<int> dalton(cantidadDalton);
    for (int i = 0; i < cantidadDalton; i++){
        std::cin >> dalton[i];
    }

    // Invariante: {0 <= w <= dalton.size() - 1}
    // Funcion cota: {dalton.size() - w}
    // Comprobamos si los daltons están ordenados
    bool daltonOrdenados = sonDalton(dalton);

    // Postcondicion: {Aw: 0 <= w < dalton.size() - 1 : dalton[w] < dalton[w + 1] || dalton[w] > dalton[w + 1]}
    // Devolvemos el resultado
    if (daltonOrdenados){
        std::cout << "DALTON\n";
    } else {
        std::cout << "DESCONOCIDOS\n";
    }

    return true;
}


int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}