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

void maxIntervalo(vector<int> const& v, int const altura, int const numEdificios, int& devInicio, int& devFinal) {

    // Inicializamos las variables
    // Buscamos el primer edificio que sea mayor que la altura del transporte, ya que nos aseguran que existe
    int i = devInicio;
    while (i < numEdificios && v[i] <= altura) {
        i++;
    }
    int provInicio = i;
    int provFinal = i;
    devInicio = i;
    devFinal = i;

    for (int i = provInicio; i < numEdificios; i++) {
        // Buscamos un edificio de mas altura que el transporte
        if (v[i] > altura) {
            // Al encontrarlo miramos cuanto mide el intervalo de edificios que inicia en ese, para evitar comprobar los que inician en otros edificios de ese propio intervalo, los cuales seran estrictamente menores
            provInicio = i;
            i++;
            while (i < numEdificios && v[i] > altura) {
                i++;
            }
            provFinal = i - 1;
            // Al terminar de recorrer el intervalo, comprobamos si es mayor que el que vamos a devolver, para quedarnos con el mayor
            if (provFinal - provInicio > devFinal - devInicio) {
                devInicio = provInicio;
                devFinal = provFinal;
            }
        }
    }
}

void resuelveCaso() {

    // Leemos los datos de entrada
    int numEdif;
    int altTrans;
    std::cin >> numEdif >> altTrans;
    vector<int> edificios(numEdif);

    for (int i = 0; i < numEdif; i++) {
        std::cin >> edificios[i];
    }

    int inicio = 0;
    int final = 0;

    // Calculamos el maximo intervalo
    // Precondicion: 0 <= numEdif <= edificios.size() && 0 < altTrans && 0 <= inicio = final < numEdif
    // Ei->[0,numEdif): edificios[i] > altTrans
    // Invariante: 0 <= provInicio <= provFinal < numEdif && 0 <= devInicio <= devFinal < numEdif && 0 <= i < numEdif &&
    // Ai->[provInicio,provFinal]U[devInicio,devFinal]: edificios[i] > altTrans &&
    // devFinal - devInicio = max(k,l: 0 <= k <= l < numEdif: Ai->[k,l] edificios[i] > altTrans: l - k)
    // Funcion de cota: numEdif - i
    // Postcondicion: 0 <= inicio <= final < numEdif && final - inicio = max(k,l: 0 <= k <= l < numEdif: Ai->[k,l] edificios[i] > altTrans: l - k)
    maxIntervalo(edificios, altTrans, numEdif, inicio, final);

    // Devolvemos la solucion
    cout << inicio << " " << final << endl;

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