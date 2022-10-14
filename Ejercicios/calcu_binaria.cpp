#include <iostream>
#include <string>

using namespace std;

int menu(){
  cout << "Para sumar ambos numeros pulse 1 y para restarlos pulse 2" << endl;
  int tecla;
  cin >> tecla;
  return tecla;
}
int main(){
  cout << "Ingrese dos numeros enteros positivos:" << endl;
  string binario = "";
  int a;
  int b;
  cin >> a >> b;
  int suma = a + b;
  int resta = a - b;
  int tecla = menu();
  if(tecla == 1){
    if (suma > 0){
      while(suma > 0){
        if(suma % 2 == 0){
          binario = "0" + binario;
        } 
        else{
          binario = "1" + binario;
        }
        suma = (int)suma/2;
      }
    } 
    else if(suma == 0){
      binario = "0";
    } 
    else{
      binario = "No se puede realizar la conversión. Ingrese solo numeros positivos";
    }
  suma = a + b;
  cout << "El resultado de la suma " << a << " + " << b << " es igual a " << suma << ", y en binario es igual a " << binario << endl;
  }
  else{
    if (resta > 0){
    while(resta > 0){
      if(resta % 2 == 0){
        binario = "0" + binario;
      } 
      else{
        binario = "1" + binario;
      }
      resta = (int)resta/2;
      }
    } 
    else if(resta == 0){
      binario = "0";
    } 
    else{
      binario = "no se puede realizar la conversión porque el resultado es negativo";
    }
    resta = a - b;
    if(resta >= 0){
      cout << "El resultado de la resta " << a << " - " << b << " es igual a " << resta << ", y en binario es igual a " << binario << endl;
    }
    else{
      cout << "El resultado de la resta " << a << " - " << b << " es igual a " << resta << " pero " << binario << endl;
    }
  }
  return 0;
}
