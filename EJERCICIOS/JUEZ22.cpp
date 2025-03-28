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

char presoFugado(vector<char> const& presos, char ini, char fin, int inicio, int final) {
    // Caso base
    if (inicio == final) {
        // Caso en el que falta el preso fin
        if (inicio == presos.size() - 1 && presos[inicio] != fin) {
            return ini + inicio + 1;
        }
        else {
            return ini + inicio;
        }
    }
    // Busqueda binaria
    int mitad = (inicio + final) / 2;
    if (presos[mitad] == ini + mitad) {
        return presoFugado(presos, ini, fin, mitad + 1, final);
    }
    else {
        return presoFugado(presos, ini, fin, inicio, mitad);
    }
}

void resuelveCaso() {
 
    char inicio, final;
    cin >> inicio >> final;

    //cout << inicio << " " << final << " " << final - inicio << " ";
    int tam = final - inicio;
    vector<char> presos(tam);
    for (int i = 0; i < tam; ++i) {
        cin >> presos[i];
    }

    cout << presoFugado(presos, inicio, final, 0, tam - 1) << "\n";

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