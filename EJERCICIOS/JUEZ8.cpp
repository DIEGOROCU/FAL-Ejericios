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

bool esNumeroPastoso (vector<int> const& v, int& n, int max, int& suma) {

    // Sumamos los valores de los elementos mayores que n
    for (int i = max - 1.; i > n; i--) {
        suma += v[i];
    }

    // Empezamos a buscar el numero pastoso
    while ( n >= 0 && v[n] != suma) {
        suma += v[n];
        n--;
    }

    // Si n es menor que 0, no hay numero pastoso, si no, si
    // Devolvemos el resultado
    if (n < 0) {
        return false;
    }
    else {
        return true;
    }

}

void resuelveCaso() {
 
    // Leemos los datos de la entrada
    int tam;
    std::cin >> tam;
    std::vector<int> vector(tam);
    for (int i = 0; i < tam; i++) {
        std::cin >> vector[i];
    }

    // Resolvemos
    int n = tam - 1;
    int suma = 0;
    // Precondicion: 0 <= n <= max <= tam && suma = 0
    // Postcondicion: n = max(0 <= i <= tam-1) : Sumatorio(i->tam) = v[i])
    // Invariante: 0 <= n <= max <= tam && suma = Sumatorio(n+1->tam)
    // Funcion cota: n
    if (esNumeroPastoso(vector, n, tam, suma)) {
        std::cout << "Si " << n << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

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