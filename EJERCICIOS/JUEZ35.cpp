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

void minimoPrecio(vector<vector<int>> const& matriz, vector<int>& cantComprados, int supermercados, int productosAComprar, int productosComprados, int& precioMinimo, int precioActual, int const& mini) {
    // Si hemos comprado todos los productos, comprobamos si el precio actual es menor que el minimo
    if (productosComprados == productosAComprar) {
        precioMinimo = min(precioMinimo, precioActual);
        return;
    }
    // Si no, seguimos calculando el tiempo
    else {
        for (int i = 0; i < supermercados; i++) {
            // Si el producto no ha sido comprado, lo compramos
            if (matriz[i][productosComprados] != -1) {
                minimoPrecio(matriz, supermercados, productosAComprar, productosComprados + 1, precioMinimo, precioActual + matriz[i][productosComprados], mini);
            }
        }
    }
    return;
}

void resuelveCaso() {
 
    int supermercados, productosAComprar;
    cin >> supermercados >> productosAComprar;
    vector<vector<int>> matriz(supermercados, vector<int>(productosAComprar));
    vector<int> productosComprados(supermercados, 0);

    for (int i = 0; i < supermercados; i++) {
        for (int j = 0; j < productosAComprar; j++) {
            cin >> matriz[i][j];
        }
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