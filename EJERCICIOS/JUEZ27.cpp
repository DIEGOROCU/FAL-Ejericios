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

// Funcion que calcula el producto de la diagonal principal de una matriz
int productoDiagonal(vector<vector<int>> const& matriz) {
    int producto =  matriz[0][0];
    for (int i = 1; i < matriz.size(); i++) {
        producto *= matriz[i][i];
    }
    return producto;
}

// Funcion que calcula el producto de la diagonal inversa de una matriz
int productoDiagonalInverso(vector<vector<int>> const& matriz) {
    int producto = matriz[0][matriz.size() - 1];
    for (int i = 1; i < matriz.size(); i++) {
        producto *= matriz[i][matriz.size() - 1 - i];
    }
    return producto;
}

bool esEquidiagonal(vector<vector<int>> const& matriz) {
    
    // Caso base, una matriz de 1x1 siempre es equidiagonal
    if (matriz.size() == 1 && matriz[0].size() == 1) return true;

    else {
        
        if (productoDiagonal(matriz) == productoDiagonalInverso(matriz)){

            // Copiamos las 4 submatrices de la matriz original
            vector<vector<int>> subMatriz1(matriz.size() / 2 , vector<int>(matriz.size() / 2));
            for (int i = 0; i < matriz.size() / 2; i++) {
                for (int j = 0; j < matriz.size() / 2; j++) {
                    subMatriz1[i][j] = matriz[i][j];
                }
            }

            vector<vector<int>> subMatriz2(matriz.size() / 2, vector<int>(matriz.size() / 2));
            for (int i = 0; i < matriz.size() / 2; i++) {
                for (int j = matriz.size() / 2; j < matriz.size(); j++) {
                    subMatriz2[i][j - matriz.size() / 2] = matriz[i][j];
                }
            }

            vector<vector<int>> subMatriz3(matriz.size() / 2, vector<int>(matriz.size() / 2));
            for (int i = matriz.size() / 2; i < matriz.size(); i++) {
                for (int j = 0; j < matriz.size() / 2; j++) {
                    subMatriz3[i - matriz.size() / 2][j] = matriz[i][j];
                }
            }

            vector<vector<int>> subMatriz4(matriz.size() / 2, vector<int>(matriz.size() / 2));
            for (int i = matriz.size() / 2; i < matriz.size(); i++) {
                for (int j = matriz.size() / 2; j < matriz.size(); j++) {
                    subMatriz4[i - matriz.size() / 2][j - matriz.size() / 2] = matriz[i][j];
                }
            }

            // Devolvemos si las 4 submatrices son equidiagonales
            return esEquidiagonal(subMatriz1) && esEquidiagonal(subMatriz2) && esEquidiagonal(subMatriz3) && esEquidiagonal(subMatriz4);
        }

        else {
            return false;
        }
        
    }

}

void resuelveCaso() {
 
    int tam;
    cin >> tam;

    vector<vector<int>> matriz(tam, vector<int>(tam));

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cin >> matriz[i][j];
        }
    }

    // Coste: T(n) = 4T(n/4) + n^2 + 2n
    // 4T(n/4) por las 4 llamaadas recursivas
    // n^2 por la copia de las 4 submatrices
    // 2n por el calculo de las diagonales
    // a = 4, b = 4, k = 2;
    // Coste: O(n^2)
    if (esEquidiagonal(matriz)) cout << "SI " << productoDiagonal(matriz) << endl;
    else cout << "NO" << endl;

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