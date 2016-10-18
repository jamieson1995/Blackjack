#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class World;

class Deck
{
private:
	World* m_world;
	int cardIndex;
	int usedCard[52];

public:
	Deck(World* _world);
	~Deck(void);
	void shuffleDeck();
	int PickCard();
	string CardFace(int currentCard);

};