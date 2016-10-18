#include "World.h"

using namespace std;

World::World(){
	player = new Player(this); //These 3 pointers allow these 3 objects too be altered outside of this class.
	dealer = new Player(this);
	deck = new Deck(this);

}


World::~World(void){
}

void World::update(){

	manager.setState(new IntroductionState(&manager, this));

	manager.update();
}