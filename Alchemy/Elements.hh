#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>


//definimos el template hash para el tipo pair
template <>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const {
		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
	}
};

class Elements {
public:
	Elements();		//guarda todos los elementos y sus claves en un unordered_map
	~Elements();
	void printElements(void);
	std::string searchValue(std::string key1, std::string key2);// Si la clave del valor al que apunta it es igual a key1 y key2, aunque esten desordenados, retorna el value

private:
	std::unordered_map<std::pair<std::string, std::string>, std::string> elements;
};