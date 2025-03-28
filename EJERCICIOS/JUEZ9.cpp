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

bool caminoApto(vector<int> const& camino, int const& desnivel, int const& cantPicos) {
    // Inicializamos las variables
    int maxDesnivel = 0;
    int i = 0;
    // Recorremos el vector hasta encontrar un desnivel demasiado alto (para ahorrar tiempo al encontrarlo) o hasta llegar al final
    while (maxDesnivel <= desnivel && i < cantPicos - 1) {
        // Si el desnivel es positivo, lo sumamos al maxDesnivel
        if (camino[i] < camino[i + 1]) {
            maxDesnivel += camino[i + 1] - camino[i];
        }
        // Si el desnivel es negativo o 0, quiere decir que no hemos encontrado un desnivel demasiado alto y ademas tenemos que volver a empezar a contar desde este punto
        else {
            maxDesnivel = 0;
        }
        i++;
    }

    // Si hemos llegado al final del vector, quiere decir que el camino es apto
    if (maxDesnivel <= desnivel) {
        return true;
    }
    else {
        return false;
    }
}

bool resuelveCaso() {
    
    // Leemos el primer dato para saber si debemos hacer un caso o no
    int desnivel;
    cin >> desnivel;

    if (!std::cin) { 
        return false;
    }
    else {

    // Leemos los datos
    int cantPicos;
    cin >> cantPicos;
    vector<int> camino(cantPicos);
    for (int i = 0; i < cantPicos; i++) {
        cin >> camino[i];
    }

    // Calculamos y devolvemos el resultado
    // Precodicion: cantPicos > 0 && Ai: 0 <= i < cantPicos camino[i] >= 0
    // Invariante: 0 <= i < cantPicos && 0 <= maxDesnivel
    // Funcion de cota: cantPicos - i
    // Postcondicion: max(i,j : 0 <= i <= j < cantPicos && (Ak,l-> [i,j]: k < l: camino[k] < camino[l]): camino[j] - camino[i] ) <= desnivel
    if (caminoApto(camino, desnivel, cantPicos)) {
        cout << "APTA" << endl;
    }
    else {
        cout << "NO APTA" << endl;
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