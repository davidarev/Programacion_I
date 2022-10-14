#include <iostream>
#include <set>

using namespace std;

int main(){
  string palabra;
  string invertida;
  set<string> palabrasInv;
  int cantidad = 0;
  while(cantidad < 10){
    cout << "Introduce una palabra: ";
    cin >> palabra;
    for(int i = palabra.size() - 1; i >= 0; i--){
      invertida += palabra[i];
    }
    palabrasInv.insert(invertida);
    invertida = ""; // 'elimino' el contenido de la variable para invertir otra palabra
    cantidad++;
  }
  cout << "El orden de las palabras invertidas por orden alfabetico es: ";
  for(auto elem: palabrasInv){
    cout << elem << ", ";
  }
}
