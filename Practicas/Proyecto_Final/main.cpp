/*
PROYECTO FINAL PROGRAMACIÓN I: JUEGO DEL AHORCADO (8 PUNTOS).
Trabajo Realizado por David Arévalo Ortega y Carlos Bermúdez Expósito.
Fecha de Inicio: 			28/12/2021.
Fecha de Finalización: 			15/01/2022.
Fecha de Entrega: 			16/01/2022.
La realizacion y la compilacion del trabajo se ha llevado a cabo en Visual Studio Code, Qt Creator y replit.com.
*/

//Librerias Utilizadas
#include <iostream>
#include <set>
#include <vector>
#include <fstream> //Manejo de archivos
#include <ctime>
#include <cstdlib>
#include <climits> //Define constantes con los límites de los tipos integrales fundamentales para el sistema y la implementación del compilador utilizado

using namespace std;

const int GANADOR = 7; //Número que representa que el usuario ganó
const int PERDEDOR = 0; //Número que representa que el usuario perdió
int vidas = 3;
const string ARCHIVO_PALABRAS = "C:/Users/Usuario/Documents/Nebrija/Progra1/Proyecto_Final/palabras.txt";  //Archivo con la lista de palabras a usar

struct Palabras{
	vector<string> palabritas;
};

struct Jugada{
	int nivel;
	int intentos = 6;
	string palabra;
	set<char> letrasAdivinadas;
	bool ganador = false;
	string palabraArriesgada;
	char ultimaLetraArriesgada;
};

//FUNCIÓN: Determina si el archivo está vacío.
bool existeArchivo(string archivo){
	ifstream infile(archivo);
	return infile.good();
}

//FUNCIÓN: Lee del archivo cada palabra almacenada y la guarda en un contenedor en memoria de acuerdo a su cantidad de letras.
Palabras cargarPalabrasTXT(){
	vector<string> palabrasJuego;
	string palabra;
	if(existeArchivo(ARCHIVO_PALABRAS)){
		ifstream archivo(ARCHIVO_PALABRAS);
		if(archivo.is_open()){
			while(getline(archivo, palabra)){
				palabrasJuego.push_back(palabra);
			}
			archivo.close();
		}
	}
	Palabras palabras;
	palabras.palabritas = palabrasJuego;
	return palabras;
}

//FUNCIÓN: Selecciona de manera aleatoria un elemento de un vector de strings y lo retorna.
string seleccionarPalabra(vector<string> palabras){
	srand(time(NULL));
	int pos = rand() % palabras.size();
	return palabras[pos];
}

//FUNCIÓN: Mostrar el dibujo en el estado actual.
void dibujo(int vidas){
	switch(vidas){
		case 6:
			cout << "__________\n|         |\n|\n|\n|\n|\n|";
			break;
		case 5:
			cout << "__________\n|         |\n|         0\n|\n|\n|\n|";
			break;
		case 4:
			cout << "__________\n|         |\n|         0\n|         |\n|\n|\n|";
			break;
		case 3:
			cout << "__________\n|         |\n|         0\n|        /|\n|\n|\n|";
			break;
		case 2:
			cout << "__________\n|         |\n|         0\n|        /|\\\n|\n|\n|";
			break;
		case 1:
			cout << "__________\n|         |\n|         0\n|        /|\\\n|        /\n|\n|";
			break;
		case PERDEDOR:
			cout << " _________\n|         |\n|         0\n|        /|\\\n|        / \\\n|\n|\n";
			break;
		case GANADOR:
			cout << "__________\n|         |\n|         \n|        \n|      0\n|     \\|/\n|     / \\\n";
			break;
	}
	cout << endl;
}

//FUNCIÓN: Mostrar el juego en el estado actual. Por cada letra adivinada, si la letra existe en la palabra se muestra en el lugar correspondiente, en caso contrario, se muestra un guión bajo " _ ".
void Juego(string palabra, set<char> letrasAdivinadas){
	for(int i = 0; i < palabra.length(); i++){
		if(letrasAdivinadas.find(palabra[i]) != letrasAdivinadas.end()){
			cout << palabra[i];
    	}
		else{
			cout << " _ ";
    	}
	}
	cout << endl;
}

//FUNCIÓN: Eliminar espacios delante y detrás de una cadena de caracteres.
string eliminarEspacios(string str){
	int i = 0;
	//Corta desde la izquierda
	while(isspace(str[i]) != 0){
		i++;
  	}
	str = str.substr(i, str.length() - i);
	//Corta desde la derecha
	i=str.length() - 1;
	while(isspace(str[i]) != 0){
		i--;
  	}
	str = str.substr(0, i + 1);
	return str;
}

//FUNCIÓN: Convertir las letras a mayusculas.
string mayusculas(string str){
	for(unsigned int i = 0; i < str.length(); i++){
		str[i] = toupper(str[i]);
	}
	return str;
}

//FUNCIÓN: Verificar si el usuario ya adivinó todas las letras de la palabra.
bool todasLasLetrasAdivinadas(set<char> letrasAdivinadas, set<char> letrasPalabra){
	for(auto elem: letrasPalabra){
		if(letrasAdivinadas.find(elem) == end(letrasAdivinadas)){
			return false;
		}
	}
	return true;
}

//FUNCIÓN: Verificar si la letra arriesgada por el usuario está en la palabra o no
bool letraEnPalabra(string palabra, char letra){
	return (palabra.find(letra) != -1);
}

/*
FUNCIÓN: Verifica el estado del juego (si el jugador ganó o no).
Si aún quedan intentos (intentos != PERDEDOR), se verifica si el jugador arriesgó una palabra y, de ser así, se verifica si coincide con la palabra en juego. 
Si no acertó la palabra, el campo intentos se pone en 0.
Si no arriesgó una palabra, se verifica si la letra arriesgada está en la palabra y, de no ser así, se decrementa el campo intentos.
Si la letra arriesgada está en la palabra, se verifica si ya acertó todas las letras de la palabra en juego.
 */
Jugada verificarJugada(Jugada jugada){
	//Si aún tiene intentos, se verifica si acertó
	if(jugada.intentos != 0){
		//Sólo puede arriesgarse una palabra una sola vez por juego.
		if(jugada.palabraArriesgada != ""){
			if(jugada.palabra == jugada.palabraArriesgada){
				jugada.ganador = true;
      		}
			else{
				jugada.ganador = false;
				jugada.intentos = 0;
				vidas--;
			}
		}
		//Si palabraArriesgada está vacío, no se arriesgó una palabra sino una letra.
		else{
			//Si la letra arriesgada no está en la palabra, se decrementa la cantidad de intentos restantes
			if(!letraEnPalabra(jugada.palabra, jugada.ultimaLetraArriesgada)){
				jugada.intentos--;
			}
			//Si ya acertó todas las letras, ganador se pone en true
			set<char> letrasPalabra;
			for(int i = 1; i != jugada.palabra.length(); i++){
				letrasPalabra.insert(jugada.palabra[i]);
			}
			if(todasLasLetrasAdivinadas(jugada.letrasAdivinadas, letrasPalabra)){
				jugada.ganador=true;
			}
		}
	}
	return jugada;
}

/*
FUNCIÓN: Ofrecer al usuario la posibilidad de "adivinar" la palabra, impidiendo incluir números en la palabra arriesgada.
 */
string arriesgarPalabra(){
	string palabra;
	do{
		cout << "\n\t\t ARRIESGAR PALABRA: "; //Usamos \t para tabular a la derecha 
		getline(cin,palabra);
		palabra = eliminarEspacios(mayusculas(palabra));
		if(palabra.find_first_of("0123456789") != string::npos){
			cout << "\t\t LA PALABRA SOLO PUEDE CONTENER LETRAS. \n\n";
		}
	}
  	while (palabra.find_first_of("0123456789") != -1);
	return palabra;
}

/*
FUNCIÓN: Ofrecer al usuario la posibilidad de "adivinar" una letra.
Si la letra ya había sido usada previamente (esté o no en la palabra) se imprime un mensaje y se pide otra.
Se valida que el dato ingresado sea una letra y no otro tipo de carácter.
 */
char arriesgarLetra(const set<char> & letras){
	char letra;  
	do{
		cout << "\t\t ADIVINAR LETRA: ";
		cin >> letra;
		letra = toupper(letra);
		if (letras.find(letra) != letras.end()){
			cout << "\t\t LETRA YA ARRIESGADA. \n\n\n";
		}
	} 
  	while((!isalpha(letra)) || (letras.find(letra) != letras.end()));
	return letra;
}

/*
FUNCIÓN: Ofrecer al usuario la posibilidad de "adivinar" una letra o la palabra entera, mostrándole un menú que le permita elegir.
Si elige arriesgar una letra, se llama a la función correspondiente y la letra se guarda en el campo ultimaLetraArriesgada, además de agregarse al campo letrasAdivinadas.
Si elige arriesgar una palabra, se llama a la función correspondiente y la palabra se guarda en el campo palabraArriesgada.
 */
Jugada arriesgar(Jugada jugada){
	int opcion;
	bool errorTipoIngresado;
	//Las opciones se muestran hasta que el usuario ingrese una opción válida
	do{
		cout << "\t Seleccionar siguiente paso: \n";
		cout << "\t\t 1: Adivinar letra \n";
		cout << "\t\t 2: Arriesgar palabra (a todo o nada!) \n";
		//Validación de ingreso de tipo de dato entero
		cout << "\n Opcion Seleccionada: ";
		cin >> opcion;
		errorTipoIngresado = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	} 
  	while (errorTipoIngresado || (opcion!=1 && opcion!=2));
	cout << endl;
	//Se arriesga una sola letra y el juego continúa si quedan más intentos
	if(opcion == 1){
		jugada.ultimaLetraArriesgada = arriesgarLetra(jugada.letrasAdivinadas);
		jugada.letrasAdivinadas.insert(jugada.ultimaLetraArriesgada);
	}
	//Se arriesga la palabra completa y el juego debe terminar
	else{
		jugada.palabraArriesgada = arriesgarPalabra();
	}
	return jugada;
}

/*
FUNCIÓN: Inicializa el juego de acuerdo al nivel seleccionado por el usuario, almacenando en el campo palabra una palabra al azar, en mayúsculas.
Luego controla el orden del desarrollo del juego.
Mientras la jugada continúa, se muestra la cantidad de intentos restantes, el dibujo de la horca en el estado actual y la palabra a adivinar. Luego se da la opción de arriesgar una letra o la palabra entera. 
Si la cantidad de intentos se redujo, se muestra un mensaje. Si la letra arriesgada es correcta, se muestra un mensaje que lo indique. Una vez finalizada la jugada, si el campo ganador está en true significa que acertó todas las letras o que arriesgó una palabra y acertó, y se muestra el dibujo correspondiente al estado GANADOR y un mensaje, y el juego termina. 
Si la jugada finalizó con el campo ganador en falso, se muestra el dibujo correspondiente al estado PERDEDOR y un mensaje, y el juego termina.
*/
int ganar;
int perder = 3;
void controlarJuego(int nivel, vector<string> palabras){
	Jugada jugada;
	jugada.nivel=nivel;
	//Elige una palabra al azar para la jugada actual y la estandariza a mayúsculas
	jugada.palabra = mayusculas(seleccionarPalabra(palabras));
	//Desarrollo del juego
	while((jugada.intentos > 0) && (!jugada.ganador)){
		cout << "\n\n\t INTENTOS RESTANTES: " << jugada.intentos << endl;
		cout << "\t VIDAS: " << vidas << endl;
		dibujo(jugada.intentos);
		cout << endl;
		Juego(jugada.palabra, jugada.letrasAdivinadas);
		cout << "\n\n";
		//Permite al usuario elegir si arriesgará una letra o la palabra
		jugada = arriesgar(jugada);
		//Verifica si el usuario acertó o no, y si ganó o perdió
		int intentoAnterior = jugada.intentos;
		jugada = verificarJugada(jugada);
		if(jugada.intentos < intentoAnterior){
			cout << "\n\t\t NOP! \n\n";
			cout << "\t\t VIDAS: " << vidas << "\n\n";
		}
		else{
			cout << "\n\t\t ACERTASTE \n";
		}
	}
	if(jugada.ganador){
		dibujo(GANADOR);
		cout << "\n\t\t ACERTASTE!!! \n\n\n";
		ganar++;
	}
	else{
		dibujo(PERDEDOR);
		cout << "La palabra era: " << jugada.palabra;
		cout << "\n\n\t\t FALLASTE! \n\n";
		perder--;
	}
}

//Inicio del programa
int main(){
  cout << "\n\t JUEGO DEL AHORCADO \n\n";
	//Inicializa cargando las palabras del archivo txt correspondiente
	Palabras palabras = cargarPalabrasTXT();
	int tecla;
	bool errorTipoIngresado;
	set<int> opcionesValidas{0, 1};
	//El menú se muestra hasta que el usuario ingrese una opción de menú válida y se vuelve a mostrar cuando termina el juego
	do{
    cout << "\t\t Seleccione una opcion: \n";
		cout << "\t\t\t 1: COMENZAR! \n";
		cout << "\t\t\t 0: Salir \n\n";
		//Validación de ingreso de tipo de dato entero
		cout << "\t Opcion seleccionada: ";
		cin >> tecla;
		errorTipoIngresado = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		//Iniciar el juego o salir
		if(opcionesValidas.find(tecla) != opcionesValidas.end()){
			switch(tecla){
			case 0:
				break;
			case 1:
				if(palabras.palabritas.empty()){
					cout << "\t ERROR: No hay palabras para ese nivel. \n";
				}
				else{
					controlarJuego(tecla, palabras.palabritas);
				}
				break;
			}
		}
		cout << "Partidas Ganadas: " << ganar << "\n\n";
		if(ganar == 2){
			tecla = 0;
		}
		if(perder == 0){
			tecla = 0;
		}
	}
	while(errorTipoIngresado || (opcionesValidas.find(tecla) == opcionesValidas.end()) || tecla != 0);
	if(vidas == 0){
		cout << "Bro que malo eres, aprende a jugar \n";
	}
	if(ganar == 2){
		cout << "Que grande eres coño \n";
	}
	return 0;
}

