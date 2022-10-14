#include <iostream>
#include <set>

using namespace std;

int main(){
  int num;
  cout << "Introduce un numero: \n";
  cin >> num;
  set<int> factores;
  //Descompongo el numero. Ej: 18, factores -> 2, 3, 3. Lo guardo en el set para que no se repitan al imprimir los numeros
  for(int i = 2; num > 1; i++){
    while(num % i == 0){
      num /= i;
      factores.insert(i);
    }
  }
  for(auto elem: factores){
    cout << elem << ", ";
  }
}
