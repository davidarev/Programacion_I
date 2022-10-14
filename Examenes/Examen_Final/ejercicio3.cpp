/*
Realizar un programa que realice los siguientes pasos:
Generar un array de 40 números enteros con valor aleatorio entre 5 y 20 (incluídos).
Mostrar el array por pantalla.
Mostrar la moda. La moda es el número que más veces aparece. (2 puntos)
Eliminar los números que estén duplicados.
Mostrar por pantalla los números ordenados (sin duplicados). (1 punto)
Mostrar por pantalla la mediana de los números sin duplicados. Si la cantidad de números es impar, la mediana es el número que se encuentra en la mitad de los números ordenados, 
si la cantidad de números es par, la mediana es la media de los 2 números centrales (2 puntos).
Si el ejercicio se realiza sin usar funciones cuando sea apropiado se valorará con una nota máxima del 60% de la puntuación prevista.
*/

#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Funciones Paso 1
int moda(array<int, 40> const & vec1, array<int, 20> const & vec2){
  int max = 0;
  int resultado = 0;
  for(int i = 0; i < vec2.size(); i++){
    if(vec2.at(i) > max){
      max = vec2.at(i);
      resultado = i;
    }
  }
  return resultado;
}
void print(array<int, 40> const & arr){
  for(auto elem: arr){
    cout << elem << ", ";
  }
  cout << endl;
}
//Funciones Paso 3
float mediana(vector<float> const & vec, int const & num){
  float resultado;
  if(num % 2 == 0){
    resultado = (vec.at(vec.size() / 2) + vec.at((vec.size() / 2) - 1)) / 2; 
  }
  else if(num % 2 == 1){
    resultado = vec.at(vec.size() / 2);
  }
  return resultado;
}

int main() {
  //Paso 1
  array<int, 40> arr;
  srand(time(NULL));
  for(int i = 0; i < arr.size(); i++){
    int numero = 5 + rand() % (20 - 5);
    arr.at(i) = numero;
  }
  cout << "El array generado es: ";
  print(arr);
  array<int, 20> posiciones; posiciones.fill(0);
  for(int elem: arr){
    posiciones.at(elem) += 1;
  }
  int Moda = moda(arr, posiciones);
  cout << "La moda es el numero " << Moda << endl;
  //Paso 2
  cout << endl;
  set<int> ordenados;
  for(auto elem: arr){
    ordenados.insert(elem);
  }
  cout << "Los numeros ordenados y sin duplicar son: ";
  for(auto elem: ordenados){
    cout << elem << ", ";
  }
  cout << endl;
  //Paso 3
  cout << endl;
  vector<float> ordenadosVec;
  for(auto elem: ordenados){
    ordenadosVec.push_back(elem);
  }
  float Mediana = mediana(ordenadosVec, ordenadosVec.size());
  cout << "La mediana es: " << Mediana;
  cout << "\n\n";
}