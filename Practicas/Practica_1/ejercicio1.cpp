#include <iostream>

using namespace std;

int main(){
  string cadena = "";
  cout << "introduzca un texto " << "\n";
  int contador = 0;
  getline(cin, cadena);
 int pos = cadena.find("a");
 while(pos != -1){
   contador++;
   pos = cadena.find("a", pos + 1);
 }
 std::cout << "La letra 'a' está: " << contador << " veces";
}