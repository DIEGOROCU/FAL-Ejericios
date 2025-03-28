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

int maximoIzq(int num) {

    if (num < 10) {
        return num;
    }
    else {
        return max(num % 10, maximoIzq(num / 10));
    }

}


int codigo(int num, int mini, bool posPar) {

    // Caso base de la recursividad
    if (num < 10) {
        return num * 3 + mini;
    }

    // Dependiendo de la paridad de la posición, se sumará un valor u otro con una llamada recursiva
    if (posPar) {
        return (num % 10) * 2 + maximoIzq(num / 10) + codigo(num / 10, min((num % 10), mini), false);
    }
    else {
        return (num % 10) * 3 + mini + codigo(num / 10, min((num % 10), mini), true);
    }

}

void resuelveCaso() {

    // Leemos los datos de entrada
    int n;
    std::cin >> n;

    // Devolvemos el resultado
    cout << codigo(n, 9, 1) << endl;

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