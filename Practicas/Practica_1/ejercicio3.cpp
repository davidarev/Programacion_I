#include <iostream>

using namespace std;

int main(){
  int contador = 1;
  int num = 2;
  int producto = 1;
  while(contador <= 5){
    int div = num / 2;
    bool esPrimo = true;
    while(div > 1){
      if(num%div==0){
      esPrimo = false;
      }
      div--;
    }
    if(esPrimo){
      producto *= num;
      contador++;
    }
    num++;
  }
  cout << "El producto es: " << producto;
}