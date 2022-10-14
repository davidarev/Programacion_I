#include <iostream>

using namespace std;

int menu(){
  int tecla;
  cout << "Elija una opción:" << endl;
  cout << "Para sumar los numeros pulse 1" << endl;
  cout << "Para restar los numeros pulse 2" << endl;
  cout << "Para multiplicar los numeros pulse 3" << endl;
  cout << "Para dividir los numeros pulse 4" << endl;
  cout << "Para intercambiar los numeros pulse 5" << endl;
  cout << "Para realizar todas las operaciones pulse 6" << endl;
  cin >> tecla;
  return tecla;
}

int main() {
  float a = 0;
  float b = 0;
  cout << "Introduce el valor entero 'a' y el valor entero 'b'" << endl;
  cin >> a >> b;
  cout << "El valor de 'a' es " << a << " y el valor de 'b' es " << b << endl;
  int tecla = menu();
  if(tecla == 1){
    int suma = a + b;
    cout << "La suma de los numeros es " << suma << endl;
  }
  else if(tecla == 2){
    int resta = a - b;
    cout << "La resta de los numeros es " << resta << endl;
  }
  else if(tecla == 3){
    int multiplicacion = a * b;
    cout << "La multiplicacion de los numeros es " << multiplicacion << endl;
  }
  else if(tecla == 4){
    float division = a / b;
    cout << "La division de los numeros es " << division << endl;
  }
  else if(tecla == 5){
    int aux;
    aux = a;
    a = b;
    cout << "Ahora 'a' es " << a << " y 'b' es " << aux << endl;
  }
  else if(tecla == 6){
    int suma = a + b;
    cout << "La suma de los numeros es " << suma << endl;
    int resta = a - b;
    cout << "La resta de los numeros es " << resta << endl;
    int multiplicacion = a * b;
    cout << "La multiplicacion de los numeros es " << multiplicacion << endl;
    float division = a / b;
    cout << "La division de los numeros es " << division << endl;
    int aux;
    aux = a;
    a = b;
    cout << "Ahora 'a' es " << a << " y 'b' es " << aux << endl;
  }
  else{
    cout << "La tecla que has pulsado no tiene una función" << endl;
  }
  return 0;
}