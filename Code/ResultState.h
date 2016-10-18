#ifndef RESULTSTATE_H
#define RESULTSTATE_H

#include "State.h"
#include "World.h"

using namespace std;

class ResultState : public State
{
public:
	ResultState(StateManager* manager, World* world);
	StateManager manager;
	void update();
	World* world;
};

#endif
