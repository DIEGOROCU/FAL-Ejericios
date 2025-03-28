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

bool esValida(vector<bool> const& aprobadas, vector<int> const& prerrequisitos,
int indice){
    if (aprobadas[indice]){
        return false;        
    }
    if (prerrequisitos[indice] != -1 && !aprobadas[prerrequisitos[indice]]){
        return false;
    }
    return true;
}

void mejorPrecioFun(vector<bool> const& aprobadas, vector<int> const& prerrequisitos,
vector<int> const& creditos, vector<int> const& coste,
bool & sePuede, int & mejorPrecio,
int precioActual, int creditosActuales, int const& creditosMin,
int const& asignaturasTotales, int asignaturasAsignadas,
int const& mini){
    if (asignaturasAsignadas == asignaturasTotales){
        if (creditosActuales >= creditosMin){
            if (!sePuede){
                sePuede = true;
                mejorPrecio = precioActual;
            }
            else {
                mejorPrecio = min(mejorPrecio, precioActual);
            }
        }
    }
    else if (!sePuede || (precioActual < mejorPrecio)) {
        if (!esValida(aprobadas, prerrequisitos, asignaturasAsignadas)){
            mejorPrecioFun(aprobadas, prerrequisitos, creditos, coste, sePuede, mejorPrecio, precioActual, creditosActuales, creditosMin, asignaturasTotales, asignaturasAsignadas + 1, mini);
        }
        else {
            mejorPrecioFun(aprobadas, prerrequisitos, creditos, coste, sePuede, mejorPrecio, precioActual, creditosActuales, creditosMin, asignaturasTotales, asignaturasAsignadas + 1, mini);
            mejorPrecioFun(aprobadas, prerrequisitos, creditos, coste, sePuede, mejorPrecio, precioActual + coste[asignaturasAsignadas], creditosActuales + creditos[asignaturasAsignadas], creditosMin, asignaturasTotales, asignaturasAsignadas + 1, mini);
        }
    }
}

void resuelveCaso() {

    int asignaturas, creditosMin;
    int mini;

    cin >> asignaturas >> creditosMin;

    vector<bool> aprobadas(asignaturas, false);
    vector<int> prerrequisitos(asignaturas);
    vector<int> creditos(asignaturas);
    vector<int> coste(asignaturas);

    for (int i = 0; i < asignaturas ; i++){
        char aux;
        cin >> aux;
        if (aux == 'A'){
            aprobadas[i] = true;
        }
    }
    for (int i = 0; i < asignaturas ; i++){
        cin >> prerrequisitos[i];
    }
    for (int i = 0; i < asignaturas ; i++){
        cin >> creditos[i];
    }
    for (int i = 0; i < asignaturas ; i++){
        cin >> coste[i];
        mini = min(mini, coste[i]);
    }

    bool sePuede = false;
    int mejorPrecio = 0;

    mejorPrecioFun(aprobadas, prerrequisitos, creditos, coste, sePuede, mejorPrecio, 0, 0, creditosMin, asignaturas, 0, mini);

    if (!sePuede){
        cout << "NO" << endl;
    }
    else {
        cout << mejorPrecio << endl;
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