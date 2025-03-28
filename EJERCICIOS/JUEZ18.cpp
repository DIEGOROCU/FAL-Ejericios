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

bool sumDivisible(int num) {

    // Caso base
    if (num < 10) {
        return true;
    }

    // Calculo de la suma de las cifras y la cantidad de cifras
    int suma = 0, numAux = num, cifras = 0;
    while (numAux > 0) {
        suma += numAux % 10;
        numAux /= 10;
        cifras++;
    }

    // Comprobacion de si la suma es divisible por la cantidad de cifras y llamamos recursivamente
    return (suma % cifras == 0) && sumDivisible(num/10);
}

bool resuelveCaso() {
    
    // Leemos el caso de prueba
    int num;
    cin >> num;

    // Comprobamos si es el centinela
    if (num <= 0) {
        return false;
    }
    else {

        // Calculamos y mostramos el resultado
        if (sumDivisible(num)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }

        return true;
    }
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