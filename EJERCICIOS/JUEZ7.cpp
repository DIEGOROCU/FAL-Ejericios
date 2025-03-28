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

// Tipo para almacenar un numero y la cantidad de veces que se repite
struct tNumero{
    long long int num;
    int cant = 0;
};

// Funcion que calcula la suma de los numeros no atipicos (long long int para evitar desbordamiento)
long long int sumaNoAtipica (vector<int> const& v, int& cant) {
    // Valores iniciales
    long long int suma = 0;
    tNumero min;
    // El minimo provisional es el primer numero
    min.num = v[0];

    for (int i = 0; i < v.size(); i++) {
        // Si hay un numero menor que el minimo, se actualiza el minimo y se suma el anterior a la suma teniendo en cuenta la cantidad de veces que se repite, y se actualiza la cantidad de numeros no atipicos 
        if (v[i] < min.num) {
            suma += min.num * min.cant;
            cant += min.cant;
            min.num = v[i];
            min.cant = 1;
        }
        // Si el numero es igual al minimo, se suma 1 a su cantidad
        else if (v[i] == min.num) {
            min.cant++;
        }
        // Si el numero es mayor que el minimo, se suma a la suma y se añade 1 a la cantidad de numeros no atipicos
        else {
            suma += v[i];
            cant++;
        }
    }

    // Devolvemos la suma de los numeros no atipicos (la cantidad de numeros no atipicos se actualiza por referencia en el bucle)
    return suma;
}

void resuelveCaso() {

    // Leemos los datos de la entrada
    int tam;
    std::cin >> tam;
    std::vector<int> numeros(tam);
    for (int i = 0; i < tam; i++) {
        std::cin >> numeros[i];
    }

    // Calculamos la suma de numeros no atipicos
    // Precondicion: {tam > 0}
    // Invariante: {0 <= cant <= i <= tam && suma = sumaNoAtipica[0...i-1]}
    // Siendo sumaNoAtipica[0,i-1] = Sum(w: 0 <= w < i: numeros[w]) - min(numeros[0...i-1]) * cant(min(numeros[0...i-1]))
    // Funcion cota: tam - i
    int cant = 0;
    long long int suma = sumaNoAtipica(numeros, cant);
    // Postcondicion: {suma = sumaNoAtipica(numeros[0...tam-1], cant)}

    // Escribimos la solucion
    std::cout << suma << " " << cant << std::endl;

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