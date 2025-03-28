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

int numComplementario(int num) {
    // Caso base, si solo tiene un digito devuelvo el complementario
    if (num < 10) {
        return 9 - num;
    }
    else {
    // Caso recursivo, devuelvo el complementario del numero sin su ultima cifra, multiplicado por 10 para mantener las posiciones, y le sumo el complementario de la ultima cifra
        return (numComplementario(num / 10) * 10) + (9 - (num % 10));
    }
}

int numComplementarioInverso(int num) {
    // Caso base, si solo tiene un digito devuelvo el complementario
    if (num < 10) {
        return 9 - num;
    }
    // Caso recursivo, devuelvo el complementario de forma analoga al anterior pero construyendo el numero al reves
    else {
        return (numComplementarioInverso(num / 10)) + ((9 - (num % 10)) * pow(10, (int)log10(num)));
    }
}

void resuelveCaso() {
 //resuelve aqui tu caso
    //Lee los datos
    int num;
    std::cin >> num;

    // Devolvemos los resultados
    std::cout << numComplementario(num) << " " << numComplementarioInverso(num) << endl;
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