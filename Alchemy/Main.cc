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

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>


//definimos el template hash para el tipo pair
template <>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const {
		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
	}
};
int main() {
	std::ifstream fentrada("elements.dat");
	if (fentrada.is_open()) {
		std::unordered_map<std::pair<std::string, std::string>, std::string> elements;
		//std::unordered_map<std::string, std::string>elements;
		
		//char linia[50];
		
		while (!fentrada.eof()) {
			std::string linia, key1, key2, value;
			bool k1 = false, k2 = false, v = false;
			getline(fentrada, linia);
			//std::cout << linia << std::endl;
			for (int i = 0; i < linia.size(); i++) {
				if (!v) {
					if (linia.at(i) != ' ' && linia.at(i+1) != '=')
						value.push_back(linia.at(i));
					else {
						v = true;
						i += 2;
					}
				}

				else if (!k1) {
					if (linia.at(i) != ' ' && linia.at(i + 1) != '+')
						key1.push_back(linia.at(i));
					else {
						k1 = true;
						i += 2;
					}
				}
				else if (!k2) {
					//if (linia.at(i) != linia.at(linia.size()))
					key2.push_back(linia.at(i));
				}
			}
			//elements[key1, key2] = {value};
			std::pair<std::string, std::string> keys;
			keys = std::make_pair(key1, key2);
			elements[keys] = { value };
		}
		for (auto it = elements.begin(); it != elements.end(); ++it) {
			std::cout << it->second << "->" << it->first.first << it->first.second << std::endl;
			
		}
			
	}
}