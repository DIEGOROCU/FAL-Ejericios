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

bool esDegradado(vector<int> const& v, int ini, int fin){

    if (ini + 1 == fin){
        return v[ini] <= v[fin];
    }
    else{

        int mitadIzq = 0, mitadDer = 0;
        int mitad = ini + ((fin - ini) / 2);

        for (int i = ini; i <= mitad; i++){
          mitadIzq += v[i];
        }
        for (int i = mitad + 1; i <= fin; i++){
          mitadDer += v[i];
        }

        return (mitadIzq <= mitadDer) && esDegradado(v, ini, mitad) && esDegradado(v, mitad + 1, fin);
    }
}
    
   

bool resuelveCaso() {
    
    int filas, columnas;
    std::cin >> filas >> columnas;
    
    if (!std::cin){
        return false;
    }
    
    else{
        
        // Lectura de la matriz
        vector<vector<int>> matriz(filas, vector<int>(columnas));
        for (int i = 0; i < filas; i++){
            for (int j = 0; j < columnas; j++){
                std::cin >> matriz[i][j];
            }
        }

        // Comprobamos si la matriz es degradada
        int f = 0;
        while (f < filas && esDegradado(matriz[f], 0, columnas - 1)){
            f++;
        }

        // Coste: 2*T(n/2) + n -> O(n log n)
        // Como hacemos esto con f*c: O(f*c log c)
        // Devolvemos si la matriz es degradada o no
        if (f == filas){
            std::cout << "SI\n";
        }
        else{
            std::cout << "NO\n";
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