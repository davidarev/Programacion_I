/*
Realizar un programa que pida al usuario que introduzca un número entero positivo por teclado y calcule el primorial. 
El primorial de un número es el resultado de multiplicar todos aquellos números enteros positivos primos menores o iguales que dicho número. Por ejemplo, el primorial de 15 es 13 x 11 x 7 x 5 x 2.
Si el ejercicio se realiza sin usar funciones cuando sea apropiado se valorará con una nota máxima del 60% de la puntuación prevista.
*/

#include <iostream>
#include <vector>

using namespace std;

bool esPrimo(int numero){
  int num = 0;
  for(int i = 1; i < (numero + 1 ); i++){
		if(numero % i == 0){
			num++;
		}
	}
	if(num != 2){
    return false;
	}
	else{
	  return true;  
	}
}
int primorial(vector<int> const & vec){
  int resultado = 1;
  for(auto elem: vec){
    resultado *= elem;
  }
  return resultado;
}

int main(){
  cout << "Introduce un numero positivo: ";
  int numero; cin >> numero;
  int num = 0;
  vector<int> primos;
  while(numero > 0){
    if(esPrimo(numero) == true){
      primos.push_back(numero);
    }
    numero--;
  }
  int resultado = primorial(primos);
  cout << "El primorial es: " << resultado;
  cout << "\n\n";
} 