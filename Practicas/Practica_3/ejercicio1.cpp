#include <iostream>
#include <vector>

using namespace std;

int main() {
  //Ejercicio 1
  cout << "Introduce una frase: \n";
  string frase;
  getline(cin, frase);
  int contadorSignos = 0;
  vector<string> palabras{};
  for(auto elem: frase){
    if(elem == '!' || elem == ';' || elem == '?'){
      contadorSignos++;
    }
  }
  if(contadorSignos == 0){
    cout << "La frase no tiene ninguno de los signos ';', '!' y '?' \n";
  }
  else{
    cout << "La frase tiene los signos ';', '!' o '?', en concreto " << contadorSignos << endl;
    /*for(auto elem: frase){
      if(elem == ' ' || elem == ';' || elem == '?' || elem == '!'){
          
      }
    }*/
  }
} 
