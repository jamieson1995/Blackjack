#include "World.h"
#include <memory>

using namespace std;

int main(){

	shared_ptr<World> world(new World()); //Smart pointer to world.
	world->Finish = 0;

	while (world->Finish == 0){
		world->update();
	}


	return 0;
}