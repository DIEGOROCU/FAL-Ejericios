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
T(n) = T(n - 1) + n
a 1 b 2 k 1
n ^ 2;
*/

int banco(int num, bool par, int & mini){

    if (num == 0){
        return 0;
    }
    else {
        if (par) {
            mini = min(mini, num % 10);
            int aux = num / 10;
            int maxi = aux % 10;
            while (aux != 0){
                maxi = max(maxi, aux % 10);
                aux /= 10;
            }
            int ret = (num % 10) * 2 + maxi;
            return banco(num / 10, !par, mini) + ret;
        }
        else {
            int ret = (num % 10) * 3 + mini;
            mini = min(mini, num % 10);
            return banco(num / 10, !par, mini) +  ret;
        }
    }

}

void resuelveCaso() {

    int num;
    cin >> num;
    int mini = 10;
    cout << banco(num, true, mini) << endl;

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