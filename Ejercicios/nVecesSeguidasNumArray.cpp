#include <iostream>
#include <array>

using namespace std;

int main(){
  array<int, 11> arr{1,2,7,7,4,3,7,7,7,7,2};
  int nVeces = 0;
  for(int i = 0; i < arr.size(); i++){
    if(arr.at(i) == 7){
      if(arr.at(i + 1) == 7){
        nVeces++;
      }
    }
  }
  cout << nVeces;
}