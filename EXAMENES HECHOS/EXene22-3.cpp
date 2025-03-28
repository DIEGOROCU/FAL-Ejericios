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

bool esValida(vector<vector<bool>> const& coinciden, vector<int> const& solucionActual, int ruta, int indice, vector<bool> const& usadas){
    if (usadas[ruta]) return false;
    if (indice - 1 >= 0 && coinciden[ruta][solucionActual[indice - 1]]){
        return false;
    }
    if (indice - 2 >= 0 && coinciden[ruta][solucionActual[indice - 2]]){
        return false;
    }
    return true;
}

void vueltaAtras(int const& rutas, int const& dias, int diasPasados, int const& mejorDia,
vector<vector<bool>> const& coinciden, vector<int> const& notas,
int notaActual, int & mejorNota,
vector<int> & solucionActual, vector<int> & mejorSolucion,
vector<bool> & usadas){

    if (diasPasados == dias){
        if (notaActual > mejorNota){
            for (int i = 0; i < dias; i++){
                mejorSolucion[i] = solucionActual[i];
            }
            mejorNota = notaActual;
        }
    }
    else if (mejorNota == -1 || notaActual + (dias - diasPasados)*mejorDia > mejorNota){
        for (int i = 0; i < rutas; i++){
            if (esValida(coinciden, solucionActual, i, diasPasados, usadas)){
                solucionActual[diasPasados] = i;
                usadas[i] = true;
                vueltaAtras(rutas, dias, diasPasados + 1, mejorDia, coinciden, notas, notaActual + notas[i], mejorNota, solucionActual, mejorSolucion, usadas);
                usadas[i] = false;
            }
        }
    }

}

void resuelveCaso() {

    int rutas, dias;
    cin >> rutas >> dias;

    vector<vector<bool>> coinciden (rutas, vector<bool> (rutas));
    for (int i = 0; i < rutas; i++){
        for (int u = 0; u < rutas; u++){
            int aux;
            cin >> aux;
            if (aux == 0) coinciden[i][u] = false;
            else coinciden[i][u] = true;
        }
    }

    int mejor = 0;
    vector<int> notas (rutas);
     for (int i = 0; i < rutas; i++){
        cin >> notas[i];
        mejor = max(mejor, notas[i]);
    }

    int mejorNota = -1;
    vector<int> solucionActual (dias);
    vector<int> mejorSolucion (dias);
    vector<bool> usadas (rutas, false);
    vueltaAtras(rutas, dias, 0, mejor, coinciden, notas, 0, mejorNota, solucionActual, mejorSolucion, usadas);

    if (mejorNota >= 0){
        cout << mejorNota << " ";
        for (int i = 0; i < dias; i++){
        cout << mejorSolucion[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "IMPOSIBLE" << endl;
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