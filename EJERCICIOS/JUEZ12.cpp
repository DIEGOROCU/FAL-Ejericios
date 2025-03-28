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

int maxIntervalo(vector<int> const& v, int const numNum) {

    // Caso 0 numeros
    if (numNum == 0){
        return 0;
    }

    // Inicializamos las variables
    int maxi = 1;
    int provMax = 1;

    // Recorremos el vector
    for (int i = 1 ; i < numNum; i++) {
        // Si el posible segmento de consecutivos sigue añadimos 1 a su longitud
        if (abs(v[i] - v[i - 1]) == 1) {
            provMax++;
        }
        // Cuando acabe el segmento guardamos el mas largo y reiniciamos el provisional
        else {
            maxi = max(maxi, provMax);
            provMax = 1;
        }
    }

    // Guardamos y devolvemos el segmento mas largo
    maxi = max(maxi, provMax);
    return maxi;
}

void resuelveCaso() {

    // Leemos los datos de entrada
    int numNum;
    std::cin >> numNum;
    vector<int> v(numNum);

    for (int i = 0; i < numNum; i++) {
        std::cin >> v[i];
    }

    // Calculamos el resultado
    // Precondicion: numNum >= 0
    // Invariante: 1 <= i <= numAltur && provMax = max(k, l: 0 <= k <= l <= i <= numAltur && (An: k <= n < l : v[n] = v[n+1] +- 1): l - k)
    // Funcion de cota: numNum - i
    // Postcondicion: dev = max(k, l: 0 <= k <= l <= numAltur && (An: k <= n < l : v[n] = v[n+1] +- 1): l - k)
    int dev = maxIntervalo(v, numNum);

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