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

/*

todosIguales(v, p, q) = (forall i : p <= i < q : v[p] = v[i])
Postcondicion iguales = #p,q : (q - p >= l) && (0 <= p <= q <= n) && (p != n)

I = 
1 <= i < n
dev = #p,q : (q - p >= l) && (0 <= p <= q <= i) && (p != i)
seguidos = max k : todosIguales(v, k, i) : i - k

Cota: n - i

*/

int iguales(vector<int> const& v, int tam, int mini){
    int seguidos = 1;
    int dev = (mini == 1);
    for (int i = 1; i < tam; i++){
        if (v[i] == v[i-1]) {
            seguidos++;
        }
        else {
            seguidos = 1;
        }
        dev += (seguidos - mini + 1) * (seguidos >= mini);

    }
    return dev;
}

void resuelveCaso() {

    int tam, mini;
    cin >> mini >> tam;
    vector<int> v(tam);
    for (int i = 0; i < tam; i++){
        cin >> v[i];
    }
    cout << iguales(v, tam, mini) << endl;

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