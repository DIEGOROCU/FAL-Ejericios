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

// Funcion que cuenta cuantos intervalos hay de longitud k que tengan igual o mas postivos que negativos en su mitad izquierda
int resolver(vector<int> const& v, int k) {

    // Inicializamos las variables que vamos a necesitar
    int numPosIz = 0;
    int numPosDr = 0;
    // Contamos cuantos positivos hay en la mitad izquierda y en la mitad derecha
    for (int i = 0; i < k/2; i++) {
        if (v[i] > 0) {
            numPosIz++;
        }
    }
    for (int i = k/2; i < k; i++) {
        if (v[i] > 0) {
            numPosDr++;
        }
    }

    int res = 0;
    int i = k - 1;
    while (i + 1 < v.size()) {
        // Si el numero de positivos en la mitad izquierda es mayor o igual que el de la mitad derecha, sumamos 1 al resultado
        if (numPosIz >= numPosDr) {
            res++;
        }

        // Actualizamos el numero de positivos en la mitad izquierda y en la mitad derecha
        numPosIz += (v[i - k/2 + 1] > 0) - (v[i - k + 1] > 0);
        numPosDr += (v[i+1] > 0) - (v[i - k/2 + 1] > 0);

        i++;

    }

    // Comprobamos si el ultimo intervalo cumple la condicion
    res += (numPosIz >= numPosDr);

    // Devolvemos el resultado
    return res;
}

bool resuelveCaso() {
    
    // Leemos si hay datos de entrada
    int n;
    std::cin >> n;
    
    if (n <= 0)
        return false;
    else {

        // Leemos los datos de entrada
        int intervalo;
        std::cin >> intervalo;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            std::cin >> v[i];
        }
            
        // Resolver problema
        int sol = resolver(v, intervalo);

        // Mostramos resultado
        std::cout << sol << std::endl;

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