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

bool solucionCorrecta(int const& universidades, vector<int> const& necesitadas, 
vector<int> const& mascPorUni) {
    for (int i = 0; i < universidades; i++){
        if (necesitadas[i] > mascPorUni[i]){
            return false;
        }
    }
    return true;
}

bool esValida(vector<int> const& necesitadas, vector<int> & mascPorUni, int const& uni){
    if (necesitadas[uni] >= mascPorUni[uni]){
        return false;
    }
    return true;
}

void vueltaAtras(int const& universidades, int const& suministradores,
vector<int> const& necesitadas, vector<int> const& cantidades, vector<int> const& precios,
int sumAsignados, int & precioActual,
bool & sePuede, int & mejorPrecio,
vector<int> & solucionActual, vector<int> & mejorSolucion, vector<int> & mascPorUni){

    if (sumAsignados == suministradores){
        if (solucionCorrecta(universidades, necesitadas, mascPorUni)){
            if (!sePuede){
                sePuede = true;
                mejorPrecio = precioActual;
                mejorSolucion = solucionActual;
            }
            else {
                mejorPrecio = min(mejorPrecio, precioActual);
                mejorSolucion = solucionActual;
            }
        }
    }
    else {
        for (int i = 0; i < universidades; i++){
            if (esValida(necesitadas, mascPorUni, i)){
                solucionActual[sumAsignados] = i;
                precioActual += precios[sumAsignados]*cantidades[sumAsignados];
                mascPorUni[i] += cantidades[sumAsignados];
                vueltaAtras(universidades, suministradores, necesitadas, cantidades, precios,
                sumAsignados + 1, precioActual, sePuede, mejorPrecio,
                solucionActual, mejorSolucion, mascPorUni);
                precioActual -= precios[sumAsignados]*cantidades[sumAsignados];
                mascPorUni[i] -= cantidades[sumAsignados];
            }
        }   
            solucionActual[sumAsignados] = universidades;
            vueltaAtras(universidades, suministradores, necesitadas, cantidades, precios,
            sumAsignados + 1, precioActual, sePuede, mejorPrecio,
            solucionActual, mejorSolucion, mascPorUni);
    }

}

void resuelveCaso() {

    int universidades, suministradores;
    cin >> universidades >> suministradores;

    vector<int> necesitadas(universidades);
    vector<int> cantidades(suministradores);
    vector<int> precios(suministradores);

    for (int i = 0; i < universidades; i++){
        cin >> necesitadas[i];
    }
    for (int i = 0; i < suministradores; i++){
        cin >> cantidades[i];
    }
    for (int i = 0; i < suministradores; i++){
        cin >> precios[i];
    }

    bool sePuede = false;
    int precioActual = 0, mejorPrecio = 0;

    vector<int> solucionActual(suministradores);
    vector<int> mejorSolucion(suministradores);
    vector<int> mascPorUni(universidades);

    vueltaAtras(universidades, suministradores, necesitadas, cantidades, precios,
                0, precioActual, sePuede, mejorPrecio,
                solucionActual, mejorSolucion, mascPorUni);

    if (sePuede) {
        cout << mejorPrecio << endl;
    }
    else {
        cout << "NO" << endl;
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