#include <iostream>
#include <array>
#include <stdlib.h>
using namespace std;

int main() {
  //apartado 2
  array<array<int, 3>, 3>matriz;
  int nFilasMatriz = 3;
  int nColumnasMatriz = 3;
  int n = nFilasMatriz * nColumnasMatriz;
  cout << "Introduce los " << n << " elementos de la Matriz 1: \n";
  for(int fila = 0; fila < 3; fila++){
    for(int columna = 0; columna < 3; columna++){
      int numero;
      cin >> numero;
      matriz.at(fila).at(columna) = numero;
      cout << numero << " , ";
    }
    cout << "\n\n";
  }
  //apartado 3
  array<array<int, 3>, 3>matriz2;
  cout << "Introduce los " << n << " elementos de la Matriz 2: \n";
  for(int fila = 0; fila < 3; fila++){
    for(int columna = 0; columna < 3; columna++){
      int numero2;
      cin >> numero2;
      matriz2.at(fila).at(columna) = numero2;
      cout << numero2 << " , ";
    }
    cout << "\n\n";
  }
  array<array<int, 3>, 3>matriz3;
  cout << "Matriz 3 que es la suma de Matriz 1 + Matriz 2: \n";
  for(int fila = 0; fila < 3; fila++){
    for(int columna = 0; columna < 3; columna++){
      int suma = matriz2.at(fila).at(columna) + matriz.at(fila).at(columna);
      cout << suma << " , ";
    }
    cout << "\n\n";
  }
  //apartado 4
  array<array<int, 3>, 3>matriz4;
  cout << "Matriz 4 que es la resta de Matriz 1 - Matriz 2: \n";
  for(int fila = 0; fila < 3; fila++){
    for(int columna = 0; columna < 3; columna++){
      int resta = matriz.at(fila).at(columna) - matriz2.at(fila).at(columna);
      cout << resta << " , ";
    }
    cout << "\n\n";
  }
  //apartado 5
  array<array<int, 3>, 3>matriz5;
  cout << "Introduce los " << n << " elementos de la Matriz 5: \n";
  for(int fila = 0; fila < 3; fila++){
    for(int columna = 0; columna < 3; columna++){
      int numero5;
      cin >> numero5;
      matriz5.at(fila).at(columna) = numero5;
      cout << numero5 << " , ";
    }
    cout << "\n\n";
  }
  int determinante = ((matriz5.at(0).at(0)*matriz5.at(1).at(1)*matriz5.at(2).at(2)) + (matriz5.at(0).at(1)*matriz5.at(1).at(2)*matriz5.at(2).at(0)) + (matriz5.at(0).at(2)*matriz5.at(1).at(0)*matriz5.at(2).at(1))) - ((matriz5.at(0).at(2)*matriz5.at(1).at(1)*matriz5.at(2).at(0)) + (matriz5.at(1).at(2)*matriz5.at(0).at(0)*matriz5.at(2).at(1)) + (matriz5.at(2).at(2)*matriz5.at(1).at(0)*matriz5.at(0).at(1)));
  cout << "El determinante de la Matriz 5 es: " << determinante << "\n";
}