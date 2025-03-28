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

bool esCaucasico(vector<int> const& v) {
    
    // Caso base, si el vector tiene 4 o menos elementos, es caucasico si o si
    if (v.size() <= 4) return true;

    // Contamos los pares de cada mitad
    int iz = 0, de = 0;
    for (int i = 0; i < v.size()/2; ++i) {
        if (v[i] % 2 == 0) iz++;
    }
    for (int i = v.size()/2; i < v.size(); ++i) {
        if (v[i] % 2 == 0) de++;
    }

    // Comprobamos si la diferencia entre los pares de cada mitad es menor o igual a 2
    bool caucasico = abs(iz - de) <= 2;

    vector <int> v1(v.begin(), v.begin() + v.size()/2);
    vector <int> v2(v.begin() + v.size()/2, v.end());

    // Si es caucasico, comprobamos si las dos mitades son caucasicas recursivamente
    return caucasico && esCaucasico(v1) && esCaucasico(v2);
     
}

bool resuelveCaso() {
 
    // Leemos los datos de entrada
    int tam;
    std::cin >> tam;
    
    // Si el tamaño es 0, terminamos
    if (tam <= 0){
        return false;
    }   
    else{

        // Leer el resto de datos
        vector<int> v(tam);
        for (int i = 0; i < tam; ++i) {
            std::cin >> v[i];
        }
        
        // Devolvemos si es caucasico o no
        // Potencia2(n) = Ek->N: n=2^k
        // Precondicion: tam > 0 && Potencia2(tam)
        // Invariante: 0 <= i <= tam
        // El problema termina ya que cada vez que se recorre el vector, se hacen dos llamadas recursivas con la mitad de elementos
        // Ademas esta el caso base de que si el vector tiene 4 o menos elementos, es caucasico si o si
        // Coste: O(nlogn) ya que la llamada recursiva es: T(n) = 2T(n/2) + n
        // a = 2 = b && k = 1 => O(n^k * logn) = O(nlogn)
        // Esto se obtiene ya que se hacen 2 llamadas recursivas con la mitad de elementos y se recorre el vector entero 1 vez (n)
        if (esCaucasico(v)) {
            std::cout << "SI\n";
        }
        else {
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