#include <iostream>
#include <array>

using namespace std;

int main(){
  array<int, 10> arr{1, 2, 3, 4, 7, 5, 9, 7, 5, 8};
  int pos;
  for(int i = 0; i < arr.size(); i++){
    if(arr.at(i) == 7){
      pos = i;
      break;
    }
  }
  cout << "El primer 7 se encuentra en la posicion: " << pos;
}