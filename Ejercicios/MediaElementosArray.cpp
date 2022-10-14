#include <iostream>
#include <array>

using namespace std;

int main(){
  //Media de los elementos de un array
  array<int, 5> arr{1, 2, 3, 4, 5};
  int suma;
  int media;
  for(auto elem: arr){
    suma += elem;
  }
  media = suma / arr.size();
  cout << "La media del array es " << media;
}