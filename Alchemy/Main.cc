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

const int POSSIBLE_COMBINATIONS = 395;



int main() {
	Player player;
	std::string playerAction;

	std::cout << "-------------------------" << std::endl;
	std::cout << "FULLENTI ALCHEMIST" << std::endl;
	std::cout << "-------------------------" << std::endl;
	player.help();

	while (player.getScore() < POSSIBLE_COMBINATIONS) {
		player.printScore();
		player.printPlayerElements();
		std::cin >> playerAction;
		system("cls");

		if (playerAction == "add") {
			int aux;
			std::cin >> aux;
			if (aux > 0 && aux < player.playerElementsSIZE()+1)
				player.add(aux - 1);
			else
				std::cout << "expression out of bounds" << std::endl;
		}
		else if (playerAction == "addBasics" || playerAction == "addbasics") {
			player.addBasics();
		}
		else if (playerAction == "delete") {
			int aux;
			std::cin >> aux;
			if (aux > 0 && aux < player.playerElementsSIZE()+1)
				player.deleteElement(aux-1);
			else
				std::cout << "expression out of bounds" << std::endl;
		}
		else if (playerAction == "info") {
			int aux;
			std::cin >> aux;
			if (aux > 0 && aux < player.playerElementsSIZE()+1)
				player.info(aux-1);
			else
				std::cout << "expression out of bounds" << std::endl;
			
		}
		else if (playerAction == "sort") {
			player.sort();
		}
		else if (playerAction == "clean") {
			player.clean();
		}
		else if (playerAction == "help") {
			player.help();
			//system("PAUSE");
		}
		else {
			int value = atoi(playerAction.c_str());
			int aux;
			std::cin >> aux;
			if (aux > 0 && aux < player.playerElementsSIZE() + 1 && value > 0 && value < player.playerElementsSIZE() + 1)
				player.combine(value - 1, aux - 1);
			else
				std::cout << "expression out of bounds" << std::endl;
		}
		std::cin.ignore(256, '\n');
	}

	std::cout << "WINNER WINNER, CHICKEN DINNER!" << std::endl;
	system("PAUSE");
	return 0;
}
