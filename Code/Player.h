#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include "StateManager.h"


using namespace std;

class World;

class Player
{
private:
	World* m_world;

	string Name;
	int HandSize;
	string HoldingCard1[2];
	string HoldingCard2[2];
	string HoldingCard3[2];
	string HoldingCard4[2];
	string HoldingCard5[2];
	string HoldingCard6[2];
	bool ace;

	int Cardvalue;
	int Handvalue;


public:
	Player(World* _world);
	~Player(void);

	int getHandSize();
	void setHandSize(int a);
	string getName();
	void setName(string N);
	void setAce(int a);
	bool getAce();
	void setHoldingCard1(string c);
	string getHoldingCard1();
	void setHoldingCard2(string c);
	string getHoldingCard2();
	void setHoldingCard3(string c);
	string getHoldingCard3();
	void setHoldingCard4(string c);
	string getHoldingCard4();
	void setHoldingCard5(string c);
	string getHoldingCard5();
	void setHoldingCard6(string c);
	string getHoldingCard6();
	void setCardValue(string c);
	int getCardValue();
	void setHandValue(int a);
	int getHandValue();
};




