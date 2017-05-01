#include "Elements.hh"

Elements::Elements()
{
	std::ifstream fentrada("elements.dat");				//abrimos el fichero elements.dat
	if (fentrada.is_open()) {							//si el fichero se ha podido abrir
		while (!fentrada.eof()) {						//que lea el fichero hasta llegar al final de este
			std::string linia, key1, key2, value;
			bool k1 = false, k2 = false, v = false;
			getline(fentrada, linia);
			//std::cout << linia << std::endl;
			for (int i = 0; i < linia.size(); i++) {
				if (!v) {
					if (/*linia.at(i) != ' ' &&*/ linia.at(i + 1) != '=')
						value.push_back(linia.at(i));
					else {
						v = true;
						i += 2;
					}
				}

				else if (!k1) {
					if (/*linia.at(i) != ' ' &&*/ linia.at(i + 1) != '+')
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
		fentrada.close();
	}
	else {
		std::cout << "File could not be open" << std::endl;
		system("PAUSE");
	}
}

Elements::~Elements()
{
	//delete(elements);
}

void Elements::printElements()
{
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		std::cout << "value: " << it->second << " -> " << "key1:" << it->first.first << " key2:" <<  it->first.second << std::endl;
	}
}

std::string Elements::searchValue(std::string key1, std::string key2)
{
	bool found(false);
	auto it = elements.begin();
	while (!found && it != elements.end())
	{
		if (it->first.first == key1 && it->first.second == key2
			|| it->first.first == key2 && it->first.second == key1) 
			found = true;
		else
			it++;
	}
	if (found)
		return it->second;
	else
		return "noValue";
}
