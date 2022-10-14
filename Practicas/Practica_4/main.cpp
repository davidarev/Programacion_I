#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//1

//2
vector<int> sum(vector<int> vec1, vector<int> vec2){
  vector<int> resultado;
  if(vec1.size() == vec2.size()){
    for(int i = 0; i < vec1.size(); i++){
      resultado.push_back(vec1[i] + vec2[i]);
    }
    return resultado;
  }
  else{
    cout << "No se pueden sumar los vectores porque sus tamaños son diferentes \n";
    return resultado;
  }
}
//3
int productoEscalar(vector<int> vec1, vector<int> vec2){
  vector<int> numsMult;
  int resultado = 0;
  if(vec1.size() == vec2.size()){
    for(int i = 0; i < vec1.size(); i++){
      numsMult.push_back(vec1.at(i) * vec2.at(i));
    }
    for(auto elem: numsMult){
      resultado += elem;
    }
    return resultado;
  }
  else{
    return -9999;
  }
}
//4
vector<int> mult(int a, vector<int> vec){
  vector<int> resultado;
  for(auto elem: vec){
    elem *= a;
    resultado.push_back(elem);
  }
  return resultado;
}
//5
float modulo(vector<int> vec1){
  vector<int> cuadrados;
  float suma = 0;
  for(auto elem: vec1){
    elem = pow(elem, 2);
    cuadrados.push_back(elem);
  }
  for(int elem: cuadrados){
    suma += elem;
  }
  float Modulo = sqrt(suma);
  return Modulo;
}

int main() {
  //1
  //vector 1
  cout << "Introduce el tamaño del vector 1: \n";
  int tamaño1;
  cin >> tamaño1;
  int cont1 = 0;
  int elemento1;
  vector<int> vector1;
  cout << "Introduce los elementos del vector 1: \n";
  while(cont1 < tamaño1){
    cin >> elemento1;
    vector1.push_back(elemento1);
    cont1++;
  }
  //vector 2
  cout << "Introduce el tamaño del vector 2: \n";
  int tamaño2;
  cin >> tamaño2;
  int cont2 = 0;
  int elemento2;
  vector<int> vector2;
  cout << "Introduce los elementos del vector 2: \n";
  while(cont2 < tamaño2){
    cin >> elemento2;
    vector2.push_back(elemento2);
    cont2++;
  }
  cout << endl;
  //2
  vector<int> suma = sum(vector1, vector2);
  if(suma.size() >= 1){
    cout << "La suma de los vectores es: ";
    for(auto elem: suma){
      cout << elem << "-";
    }
    cout << endl;
  }
  //3

  //4
  int productoEscalarr = productoEscalar(vector1, vector2);
  cout << "El producto escalar de los vectores es: " << productoEscalarr << endl;
  //5
  cout << "Introduce el numero por el que quieres multiplicar el primer vector: ";
  int numMult;
  cin >> numMult;
  cout << "El vector 1 multiplicado por el numero '" << numMult << "' es: ";
  vector<int> vecMult = mult(numMult, vector1);
    for(auto elem: vecMult){
    cout << elem << "-";
  }
  cout << endl;
  //6
  float moduloo = modulo(vector1);
  cout << "El modulo del vector 1 es: " << moduloo << endl;
} 