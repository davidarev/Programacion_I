#include <iostream>

using namespace std;
int main(){
  int num1 = 1;
  int num2 = 1;
  int num3;
  int producto = 1;
  for(int i = 0; i < 19; i++){
    num3 = num1;
    num1 = num2 + num3;
    num2 = num3;
    producto += num3;
  }
  cout << "La suma de los primeros 20 elementos es: " << producto;
}