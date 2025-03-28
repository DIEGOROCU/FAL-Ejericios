/**
 * Escribid el nombre y usuario del juez los miembros de la pareja:
 * Nombre y usuario:
 * Nombre y usuario:
 *
 * Explica brevemente el algoritmo:
 * Se recorre el vector contando comprobando si tenemos una cadena de elementos iguales, contando
 * la longitud de la misma
 * Cuando encontremos un elemento distinto al anterior, comrpobamos si es mayor
 * En caso de serlo, ya tenemos la presa
 * Si no lo es, reiniciamos el contador (a 1 ya que empieza con el propio elemento)
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* 
 *
 * Escribe la precondicion 
 * {1 <= v.size() <= 10^8 && 1 <= t <= v.size()}
 */

bool construccion(const vector<int>& v, int t) /*dev b */ {
   bool b = false;
   //Escribe tu código

   int tam = v.size();
   int cont = 1;

    for (int i = 1; i < tam; i++){
        if (v[i] == v[i-1]){
            cont++;
        }
        else {
            if (cont >= t && v[i] > v[i - 1]) {
                b = true;
            }
            cont = 1;
        }
    }
    
    //Escribe la funcion de cota
    // v.size() - i (mayor que 0 siempre, disminuye en cada iteracion)
    //Escribe el invariante
    // cont = #k 0 <= k < i: forAll(p: k <= p < i: v[k] == v[p]) 
	return b;
}
/* Escribe la definicion de llano_acotado(v,p,q) 
* llano_acotado(v,p,q) = {forAll k->[p,q): v[k] == v[p] && v[q] > v[p]}
* Usando llano_acotado escribe la postcondicion
* {b = Ep,q: llano_acotado(v,p,q) && q - p >= t}
*/
//Analiza el coste de la funcion
// El coste es de O(v.size())
// Ya que se recorren todos los elementos del vector menos el primero (v.size() - 1)
// Y en cada iteracion (se mira 1 elemento) se realizan hasta 3 comprobaciones y hasta 2 operaciones
// Como mucho, todas de coste lineal O(1) lo que implica que el coste total es O(v.size())




bool resuelveCaso() {
    // leer los datos de la entrada
    int N, T; //número de datos, espacio
    cin >> N >> T;
    if(N == 0 && T == 0)
        return false;
    vector<int> valores(N);
    for(int i = 0; i < N; ++i){
        int e;  cin >> e;
        valores[i] = e;
    }

    //Llama a la función
    bool b = construccion(valores, T);
    
    if(b)
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}