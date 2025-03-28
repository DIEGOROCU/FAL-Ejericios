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

int minimoDivideYVencerass(vector<int> const& v) {

    // Caso base
    if (v.size() == 1) return v[0];

    vector<int> v1(v.begin(), v.begin() + v.size() / 2);
    vector<int> v2(v.begin() + v.size() / 2, v.end());

    // Llamada recursiva con divide y vencerás
    return min(minimoDivideYVencerass(v1), minimoDivideYVencerass(v2));
}

bool resuelveCaso() {
    
    // Leemos el dato de entrada
    int tam;
    cin >> tam;
    
    // Comprobamos si hay un caso de entrada
    if (!std::cin)
        return false;

    else {

        // Leemos el resto de datos
        vector<int> v(tam);
        for (int i = 0; i < tam; i++) {
            cin >> v[i];
        }

        // Devolvemos el resultado
        // El coste es O(nlogn) ya que: 2T(n/2) + n + k = O(nlogn)
        // n sale ya que copiamos el vector en cada llamada recursiva
        cout << minimoDivideYVencerass(v) << '\n';

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