#ifndef INTRODUCTIONSTATE_H
#define INTRODUCTIONSTATE_H

#include "State.h"
#include "World.h"

using namespace std;

class IntroductionState : public State
{
public:
	IntroductionState(StateManager* manager, World* world);
	StateManager manager;
	void update();
	World* world;
};

#endif
