#ifndef DEALERSTATE_H
#define DEALERSTATE_H

#include "State.h"
#include "World.h"

using namespace std;

class DealerState : public State
{
public:
	DealerState(StateManager* manager, World* world);
	StateManager manager;
	void update();
	World* world;
};

#endif
