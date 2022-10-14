#include <iostream>

using namespace std;

int dato;

struct Nodo{
  int dato;
  Nodo *next;
};
void insertarLista(Nodo *&lista, int n){
  Nodo *nodo2 = new Nodo();
  nodo2 -> dato = n;

  Nodo *aux1 = lista;
  Nodo *aux2;

  while(aux1 != NULL && aux1 -> dato < n){
    aux2 = aux1;
    aux1 = aux1 -> next;
  }
  if(lista == aux1){
    lista = nodo2;
  }
  else{
    aux2 -> next = nodo2;
  }
  nodo2 -> next = aux1;
  cout << "El elemento " << n << " se inserto correctamente. ";
} 

void mostrarLista(Nodo *lista){
  Nodo *actual = new Nodo();
  actual = lista;
  cout << "Los elementos de la lista son: ";
  while(actual != NULL){
    cout << actual -> dato << ", ";
    actual = actual -> next;
  }
}

void buscarLista(Nodo *lista, int n){
  bool condition = false;
  Nodo *actual = new Nodo();
  actual = lista;
  while(actual != NULL && actual -> dato <= n){
    if(actual -> dato == n){
      condition = true;
    }
    actual = actual -> next;
  }
  if(condition == true){
    cout << "El elemento que buscas existe en la lista" << endl;
  }
  else{
    cout << "El elemento que buscas no existe en la lista" << endl;
  }
}
void eliminarNodo(Nodo *&lista, int n){
  if(lista == NULL){
    cout << "La lista esta vacia" << endl;
  }
  else{
    Nodo *auxBorrar = lista;
    Nodo *anterior = NULL;
    while(auxBorrar != NULL && auxBorrar -> dato != n){
      anterior = auxBorrar;
      auxBorrar = auxBorrar -> next;
    }
    if(auxBorrar == NULL){
      cout << "El elemento que quieres eliminar no existe" << endl;
    }
    else if(anterior == NULL){
      lista = lista -> next;
      delete auxBorrar;
      cout << "El elemento " << dato << " ha sido eliminado. ";
    }
    else{
      anterior -> next = auxBorrar -> next;
      delete auxBorrar;
      cout << "El elemento " << dato << " ha sido eliminado. ";
    }
  }
}

int main(){
  Nodo *lista = NULL;
  int nVeces;
  cout << "¿Cuantos datos quiere añadir a la lista?" << endl;
  cin >> nVeces;
  cout << endl;
  for(int i = 1; i <= nVeces; i++){
    cout << "Introduzca el elemento:" << endl;
    cin >> dato;
    if(nVeces - i == 1){
      insertarLista(lista, dato);
      cout << "Le quedar por insertar un elemento" << endl << endl;
    }
    else if(i < nVeces){
      insertarLista(lista, dato);
      cout << "Le quedan por insertar " << nVeces - i << " elementos" << endl << endl;
    }
    else{
      insertarLista(lista, dato);
      cout << "Ya no hay mas elementos que insertar" << endl << endl;
    }
  }
  mostrarLista(lista);
  cout << endl << endl;
  cout << "¿Hay algun elemento que estes buscando? Escriba 'si' o 'no'" << endl; 
  string respuesta;
  cin >> respuesta;
  if(respuesta == "si"){
    cout << "¿Que elemento buscas?" << endl;
    cin >> dato;
    buscarLista(lista, dato);
  }
  else{
    cout << "Okay";
  }
  cout << endl << endl;
  cout << "¿Hay algun elemento que quieras eliminar? Escriba 'si' o 'no'" << endl; 
  cin >> respuesta;
  if(respuesta == "si"){
    cout << "¿Que elemento quieres eliminar?" << endl;
    cin >> dato;
    eliminarNodo(lista, dato);
    mostrarLista(lista);
    cout << endl;
    return 0;
  }
  else{
    cout << "Okay" << endl;
    return 0;
  }
}
