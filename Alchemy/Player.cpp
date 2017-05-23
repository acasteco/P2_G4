#include "Player.hh"



Player::Player()
{
	addBasics();
}

Player::~Player()
{
}

void Player::combine(int k1, int k2)
{
	if (k1 > k2) {
		int temp = k1;
		k1 = k2;
		k2 = temp;
	}
	if (k1 == k2) {
		std::cout << "No puedes combinar un elemento consigo mismo" << std::endl;
		return;
	}
	std::string aux = elements.searchValue(playerElements[k1], playerElements[k2]);
	
	if (aux == "noValue")
		std::cout << "No existe esta combinacion" << std::endl;
	else {
		if (newElement(aux)) {
			std::cout << "New Element Discovered: " << aux << std::endl;
			score++;
		}
		playerElements.insert(playerElements.end(), aux);
		playerElements.erase(playerElements.begin() + k1);
		playerElements.erase(playerElements.begin() + k2 - 1);
	}
}

void Player::addBasics()
{
	playerElements.push_back("Air");
	playerElements.push_back("Fire");
	playerElements.push_back("Earth");
	playerElements.push_back("Water");
}

void Player::add(int el)
{
	playerElements.push_back(playerElements.at(el));
}

void Player::deleteElement(int el)
{
	playerElements.erase(playerElements.begin() + (el));
}

void Player::sort()
{
	std::sort(playerElements.begin(), playerElements.end());
}

void Player::clean()
{
	std::set <std::string> aux;
	while (playerElements.size() != 0) {
		aux.insert(playerElements.front());
		playerElements.erase(playerElements.begin());
	}
	for (auto it = aux.begin(); it != aux.end(); it++) {
		playerElements.push_back(*it);
	}
	aux.clear();
}

void Player::info(int aux)
{
	std::string wiki = "https://en.wikipedia.org/wiki/";
	std::string url;
	url.operator+=(wiki);
	url.operator+=(playerElements[aux]);

	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void Player::help()
{
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
	std::cout << "- Enter 'addBasics' to add new instances  of the 4 basics elements " << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list. " << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	std::cout << std::endl;
	std::cout << "Your current score:" << score << std::endl;
	std::cout << "You have these elements:" << std::endl;
}

void Player::printPlayerElements()
{
	//for (auto &x : playerElements) { std::cout << x << std::endl; }
	for (int i = 0; i < playerElements.size(); i++) {
		std::cout << i + 1 << "- " << playerElements[i] << std::endl;
	}
}

void Player::printScore()
{
	std::cout << "Score: " << score << std::endl;
}

int Player::getScore()
{
	return score;
}

bool Player::newElement(std::string aux)
{
	if (elementsFound.find(aux) != elementsFound.end() || elementsFound.size() == 0) {
		elementsFound.insert(aux);
		return true;
	}
	else
		return false;
}

int Player::playerElementsSIZE()
{
	return playerElements.size();
}
