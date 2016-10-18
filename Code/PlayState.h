#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "World.h"

using namespace std;

class PlayState : public State
{
public:
	PlayState(StateManager* manager, World* world);
	StateManager manager;
	void update();
	World* world;
};

#endif
