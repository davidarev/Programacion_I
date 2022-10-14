#include <iostream>
#include <vector>

using namespace std;

int main() {
    //Ejercicio 2
    float num1 = 8;
    float num2 = 7;
    float num3;
    int cant;
    float max = 0;
    float min = 0;
    vector<float> numeros{8, 7};
    vector<float> numerosPos{};
    vector<float> numerosNeg{};
    cout << "¿Cuantos terminos de la serie quieres que te enseñe? \n";
    cin >> cant;
    cout << "Los primeros " << cant << " terminos de la serie son: ";
    for(int i = 0; i < cant - 2; i++){
        num3 = num2 - (num1 / 2);
        numeros.push_back(num3);
        num1 = num2;
        num2 = num3;
    }
    for(auto elem: numeros){
        cout << elem << ", ";
        if(min > elem){
        min = elem;
        }
        else if(max < elem){
        max = elem;
        } 
    }
    cout << endl;
    cout << "El mayor numero de la serie es el: " << max << " y el menor numero de la serie es el: " << min << endl;
    for(auto elem: numeros){
      if(elem >= 0){
        numerosPos.push_back(elem);
      }
      else{
        numerosNeg.push_back(elem);
      }
    }
    cout << "Los numeros positivos son: ";
    for(auto elem: numerosPos){
      cout << elem << ", ";
    }
    cout << endl;
    cout << "Los numeros negativos son: ";
    for(auto elem: numerosNeg){
      cout << elem << ", ";
    }
    cout << endl;
} 