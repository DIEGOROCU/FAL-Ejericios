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

int maxIntervalo(vector<int> const& v, int const numAltur) {

    // Caso 0 alturas
    if (numAltur == 0){
        return 0;
    }

    // Inicializamos las variables
    int maxi = 1;
    int provMax = 1;

    // Recorremos el vector
    for (int i = 1 ; i < numAltur; i++) {
        // Si la posible pista sigue añadimos 1 a su longitud
        if (v[i] <= v[i-1]){
            provMax++;
        }
        // Cuando acabe la pista guardamos la mas larga y reiniciamos la provisional
        else {
            maxi = max(maxi, provMax);
            provMax = 1;
        }
    }

    // Guardamos y devolvemos la pista mas larga
    maxi = max(maxi, provMax);
    return maxi;
}

void resuelveCaso() {

    // Leemos los datos de entrada
    int numAltur;
    std::cin >> numAltur;
    vector<int> pista(numAltur);

    for (int i = 0; i < numAltur; i++) {
        std::cin >> pista[i];
    }

    // Calculamos el resultado
    // Precondicion: numAltur > 0 && Ai -> [0, numAltur) pista[i] > 0
    // Invariante: 1 <= i <= numAltur && maxi = max(k, l: 0 <= k <= l <= i <= numAltur : (k <= n < m <= l : pista[n] <= pista[m]): l - k)
    // Funcion de cota: numAltur - i
    // Postcondicion: maxi = max(k, l: 0 <= k <= l <= numAltur : (k <= n < m <= l : pista[n] <= pista[m]): l - k)
    // Coste: O(n) siendo n el numero de alturas, ya que recorremos el vector una vez pasando por cada altura una unica vez
    int dev = maxIntervalo(pista, numAltur);

    // Devolvemos la solucion
    cout << dev << endl;

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