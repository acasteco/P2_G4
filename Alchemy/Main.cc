/*
class Elements{
constructor: leer fichero "elements.data"(getline())) y los almacena en el unordered map (comprovar con un contador, que se han cargado todos los elementos, else System("pause"))
unordered map usando los elementos que se combinan como key, y lo que obtenemos como value
}
class Player{

public:
(constructor, deve crear el vector con los elementos aire, fuego, tierra y agua)
combine(elemento 1, elemento 2) -> elimina los 2 elementos y pone el resultado en la ultima posicion del vector. Y suma 1 a la puntuacion
add() -> (copia del elemento)
addBasics() -> (vuelve a añadir los elementos primarios)
deleteElement() -> (borra elemento y posicion de memoriua que ocupaba)
info(posicion elemento) -> abre pagina de wikipedia
sort() -> se ordena el vector alafabeticamente
clean() -> elimina los elementos repetidos (set -> estructura de datos no repetidos sin key que no añade elementos repetidos)
help() -> muestra un tutorial con todas las acciones que puede hacer el jugador

private:
int puntuacion(+1 cada vez que creamos un elemento nuevo)
vector para almacenar los elementos creados

}
*/
#include "Elements.hh"
#include "Player.hh"
#include <iostream>
#include <string>




int main() {
	std::cout << "-------------------------" << std::endl;
	std::cout << "FULLENTI ALCHEMIST" << std::endl;
	std::cout << "-------------------------" << std::endl;

	//Elements elem;
	//elem.printElements();
	Player player;
	player.help();
	player.printPlayerElements();
	player.printScore();
	system("PAUSE");
	system("cls");
	player.combine(0, 2);
	player.printScore();
	player.addBasics();
	player.add(2);
	player.printPlayerElements();
	system("PAUSE");
	system("cls");
	//player.sort();
	player.clean();
	player.printScore();
	player.printPlayerElements();
	
	return 0;

}
