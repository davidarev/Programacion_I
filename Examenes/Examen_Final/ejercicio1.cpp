/*
Realizar un programa que pida al usuario que introduzca un número entero positivo por teclado y calcule el semifactorial. 
El semifactorial es el resultado de multiplicar el número por todos aquellos números enteros positivos menores que él que tienen la misma paridad. Por ejemplo, el semifactorial de 7 es 7 x 5 x 3 x 1.
Si el ejercicio se realiza sin usar funciones cuando sea apropiado se valorará con una nota máxima del 60% de la puntuación prevista.
*/

#include <iostream>

using namespace std;

int semifactorial(int & num){
  int resultado = 1;
  while(num > 0){
    resultado *= num;
    num = num - 2;
  }
  return resultado;
}

int main() {
  cout << "Introduce un numero entero positivo: ";
  int num; cin >> num;
  int resultado = semifactorial(num);
  cout << "El semifactorial es: " << resultado;
  cout << "\n\n";
} 