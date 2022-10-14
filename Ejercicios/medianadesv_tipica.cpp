
#include <iostream>
#include<random>
#include <time.h>
#include<vector>
#include<math.h>

using namespace std;

vector<int> aleatorio(vector<int> ale, int n, int j, int k){
    int num;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
       num = 1 + rand() % (j - k);
       ale.push_back(num);
       cout << ale.at(i)<<" ";
    }
    return ale;
}

float media(vector<int> ale){
    int aux = 0;
    for(int i = 0; i < ale.size(); i++){
        aux += ale.at(i);
    }
    return aux / ale.size();
}

float desv(vector<int> ale){
    int aux = 0;
    for(int i = 0; i < ale.size(); i++){
        aux += pow((ale.at(i) - media(ale)), 2);
    }
    return aux / ale.size();
}
int mediana(vector<int> ale){
    int aux = 0;
    aux = (ale.size() - 1) / 2;
    return ale.at(aux);

}

int main(){
    unsigned int num, n1, n2, c;
    vector<int>v;

 cout<<"Cuantos numeros aleatorios quieres: "<<endl;
 cin>>num;
 cout<<"Entre que valores quieres: "<<endl;
 cin>>n1;
 cin>>n2;
 v=aleatorio (v, num, n1, n2);
 cout<<endl;
 do{
     cout<<"1. Calcular media"<<endl;
     cout<<"2. Calcular Desviacion tipica"<<endl;
     cout<<"3. Calcular mediana"<<endl;
     cout<<"4. Calcular nuevo vector de numeros aleatorios"<<endl;
     cout<<"5. Salir"<<endl;
     cin>>c;
     switch(c){
     case 1:
         cout<<media (v);
         system ("pause");
         break;
     case 2:
         cout<<desv (v);
         system ("pause");
         break;
     case 3:
        cout<<mediana (v);
         system ("pause");
         break;
     case 4:
        v=aleatorio(v, num, n1, n2);
        system ("pause");
         break;
     case 5:
         cout<<"Adios"<<endl;
         system ("pause");
         break;
     default:
       cout<<"Opcion invalida"<<endl;
       system ("pause");
       break;

     }
     system ("cls");

 }
 while(c!=5);

 /*
 cout<<media(v);
 cout<<desv (v);
 cout<<mediana(v);
*/
    return 0;
}
