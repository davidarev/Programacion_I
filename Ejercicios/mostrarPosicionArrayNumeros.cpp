#include <iostream>
#include <array>

using namespace std;

int main(){
  array<int, 5> arr{1, 7, 3, 7, 2}; 
  int cont;
  cout << "La/s posicion/es en la/s que se encuentra el 7 es/son: ";
  for(int pos = 0; pos < arr.size(); pos++){
    if(arr.at(pos) == 7){
      cout << pos << ", ";
    }
  }
}