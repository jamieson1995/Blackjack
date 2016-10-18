#include "ResultState.h"


ResultState::ResultState(StateManager* manager, World* world) : State(manager)
{
	this->world = world;
}

void ResultState::update(){

	system("cls");
	Sleep(2000);
	cout << "Final results." << endl;
	cout << endl;

	bool PlayerBust = false;
	bool DealerBust = false;

	Sleep(1000);
	cout << "Your final hand value was: " << world->player->getHandValue() << endl;
	cout << endl;

	if ( (world->player->getHandValue() <= 21) && (world->dealer->getHandValue() <= 21) ){
		Sleep(1000);
		cout << "The dealer's final hand value was: " << world->dealer->getHandValue() << endl;
		cout << endl;
	}
	if (world->player->getHandValue() > 21){
		Sleep(1000);
		cout << "You are bust!" << endl;
		cout << endl;
		PlayerBust = true;
	}
	if ( (PlayerBust == false) && (world->dealer->getHandValue() > 21) ){
		Sleep(1000);
		cout << "The dealer is bust!" << endl;
		cout << endl;
		DealerBust = true;
		}

	if (PlayerBust == true){

		Sleep(1000);
		cout << "You are bust, so the dealer wins. Sorry about that." << endl;
		cout << endl;

	}
	if ( (PlayerBust == false) && (DealerBust == true) ){

		Sleep(1000);
		cout << "Congratulations. The dealer is bust and you're not. You have won." << endl;
		cout << endl;

	}
	if ( (PlayerBust == false) && (DealerBust == false) ){
		if (world->player->getHandValue() == world->dealer->getHandValue()){
			Sleep(1000);
			cout << "You and the dealer both have the same hand value, therefore ";
			cout << "it's a draw." << endl;
			cout << endl;
		}
		if (world->player->getHandValue() < world->dealer->getHandValue()){
			Sleep(1000);
			cout << "The dealer has a higher hand value. The dealer wins." << endl;
			cout << endl;
		}
		if (world->player->getHandValue() > world->dealer->getHandValue()){
			Sleep(1000);
			cout << "Congratulations. You have a higher hand value. You have won." << endl;
			cout << endl;
		}

	}
	
	Sleep(2000);

	char finish;

	Sleep(2000);
	cout << "Please enter anything to exit the game: ";
	cin >> finish;
	cout << endl;

	world->Finish = 1;
}