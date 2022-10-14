#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    //Ejercicio 3
    cout << "¿Quereis empezar una partida? (si o no) \n";
    string respuesta;
    cin >> respuesta;
    if(respuesta == "si"){
      int victoriaPLY1 = 0;
      int victoriaPLY2 = 0;
      int ronda = 1;
      srand(time(NULL));
      while(victoriaPLY1 < 3 && victoriaPLY2 < 3){
        cout << "RONDA " << ronda << endl;
        //Jugador 1
        int numPLY1 = 1 + rand() % (4 - 1);
        if(numPLY1 == 1){
          cout << "El jugador 1 ha sacado tijera \n";
        }
        else if(numPLY1 == 2){
          cout << "El jugador 1 ha sacado piedra \n";
        }
        else{
          cout << "El jugador 1 ha sacado papel \n";
        }
        //Jugador 2
        int numPLY2 = 1 + rand() % (4 - 1);
        if(numPLY2 == 1){
          cout << "El jugador 2 ha sacado tijera \n";
        }
        else if(numPLY2 == 2){
          cout << "El jugador 2 ha sacado piedra \n";
        }
        else{
          cout << "El jugador 2 ha sacado papel \n";
        }
        //Comparativa de Resultados
        if(numPLY1 == numPLY2){
          cout << "El punto no se lo lleva ninguno ya que habeis empatado \n";
        }
        else if(numPLY1 == 1 && numPLY2 == 2){
          cout << "Victoria de esta ronda para el jugador 2 \n";
          victoriaPLY2++;
        }
        else if(numPLY1 == 1 && numPLY2 == 3){
          cout << "Victoria de esta ronda para el jugador 1 \n";
          victoriaPLY1++;
        }
        else if(numPLY1 == 2 && numPLY2 == 1){
          cout << "Victoria de esta ronda para el jugador 1 \n";
          victoriaPLY1++;
        }
        else if(numPLY1 == 3 && numPLY2 == 1){
          cout << "Victoria de esta ronda para el jugador 2 \n";
          victoriaPLY2++;
        }
        else if(numPLY1 == 2 && numPLY2 == 3){
          cout << "Victoria de esta ronda para el jugador 2 \n";
          victoriaPLY2++;
        }
        else if(numPLY1 == 3 && numPLY2 == 2){
          cout << "Victoria de esta ronda para el jugador 1 \n";
          victoriaPLY1++;
        }
        //Recuento
        cout << "Puntos Jugador 1: " << victoriaPLY1 << endl;
        cout << "Puntos Jugador 2: " << victoriaPLY2 << endl;
        ronda++;
        cout << endl;
      }
      cout << "EL JUEGO HA TERMINADO \n";
      if(victoriaPLY1 > victoriaPLY2){
        cout << "Ha ganado el Jugador 1";
      }
      else{
        cout << "Ha ganado el Jugador 2";
      }
    }
    else{
      cout << "Pues hasta luego";
    }
} 