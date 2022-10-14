#include <iostream>


using namespace std;

int main(){
  cout << "Introduce un texto: ";
  string frase = " ";
  int numLetras = 0;
  int numEspacios = 0;
  int numPalabras = 0;
  getline(cin, frase);
  for(auto elem: frase){
    numLetras++;
    if(elem == ' '){
      numLetras--;
      numEspacios++;
    }
  }
  cout << "El numero de letras es: " << numLetras << endl;
  for(auto elem: frase){
    if(elem == ' '){
      if(elem - 1 != ' ' && elem + 1 != ' '){
        numPalabras++;
      }
    }
  }
  cout << "El numero de palabras es: " << numPalabras + 1;

}