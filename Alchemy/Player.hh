#pragma once

#include "Elements.hh"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <Windows.h>
#include <algorithm>

class Player
{
public:
	Player();
	~Player();
	void combine(int k1, int k2);
	void addBasics();
	void add(int el);
	void deleteElement(int el);
	void sort();
	void clean();
	void info();
	void help();

	void printPlayerElements();
	void printScore();				//puntuacao
	bool newElement(std::string aux);
private:
	Elements elements;
	int score;
	std::vector<std::string> playerElements;
	std::set<std::string> elementsFound;
};

