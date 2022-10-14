#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  int puntosJug1 = 0;
  int puntosJug2 = 0;
  srand(time(NULL));
  int bola1;
  int bola2;
  string respuesta1 = "no";
  string respuesta2 = "no";
  while(respuesta1 == "no" || respuesta2 == "no"){ //Mientras uno de los dos no se plante el juego sigue
    while(respuesta1 == "no"){
      cout << "TURNO JUGADOR 1 \n";
      bola1 = 1 + rand() % (11 - 1); 
      cout << "Has sacado la bola numero " << bola1 << endl; 
      puntosJug1 += bola1;
      cout << "Tienes " << puntosJug1 << " puntos \n";
      cout << "¿Te plantas Jugador 1? Responder 'si' o 'no' ";
      cin >> respuesta1;
      cout << endl;
      break; //rompo el bucle y paso al siguiente
    }
    while(respuesta2 == "no"){
      cout << "TURNO JUGADOR 2 \n";
      bola2 = 1 + rand() % (11 - 1); 
      cout << "Has sacado la bola numero " << bola2 << endl; 
      puntosJug2 += bola2;
      cout << "Tienes " << puntosJug2 << " puntos \n";
      cout << "¿Te plantas Jugador 2? Responder 'si' o 'no' ";
      cin >> respuesta2;
      cout << endl;
      break; //rompo el bucle y vuelvo al inicio si la condicion del primer bucle se cumple
    }
  }
  cout << "RECUENTO: Puntos Jugador 1: " << puntosJug1 << ". Puntos Jugador 2: " << puntosJug2 << " Ganará el jugador que haya obtenido la puntuacion mas cercana o igual a 15" << endl;
  int Dif1 = 0;
  int Dif2 = 0;
  //Hallo las diferencias y las comparo para determinar el ganador
  if(puntosJug1 > 15){
    Dif1 = puntosJug1 - 15;
  }
  else{
    Dif1 = 15 - puntosJug1; 
  }
  if(puntosJug2 > 15){
    Dif2 = puntosJug2 - 15;
  }
  else{
    Dif2 = 15 - puntosJug2; 
  }
  if(Dif1 > Dif2){
    cout << "HA GANADO EL JUGADOR 2";
  }
  else if(Dif1 < Dif2){
    cout << "HA GANADO EL JUGADOR 1";
  }
  else{
    cout << "HABEIS EMPATADO";
  }
}
