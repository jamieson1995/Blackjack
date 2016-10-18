#pragma once
#include <string>
#include "Player.h"
#include "Deck.h"
#include "PlayState.h"
#include "State.h"
#include "StateManager.h"
#include "IntroductionState.h"
#include "DealerState.h"
#include "ResultState.h"

class World
{
private:

public:
	int Finish;
	StateManager manager;
	Player* player;
	Player* dealer;
	Deck* deck;
	World(void);
	~World(void);
	void update();
};
