#include "PlayState.h"
#include "StateManager.h"

#include <iostream>

PlayState::PlayState(StateManager* manager, World* world) : State(manager)
{
	this->world = world;
}

void PlayState::update(){

	int AceValue = 11;

	Sleep(2000);
	cout << world->player->getName() << " it's your turn." << endl;
	Sleep(2000);
	
	char Play = 'H';
	int first = 1;

	Sleep(1000);
	system("cls");
	cout << "You have " << world->player->getHandSize() << " cards." << endl;
	cout << endl;

	for (int i = 1; i <= world->player->getHandSize(); i++){
		switch (i){
			case 1:
				Sleep(1000);
				cout << "Card 1: ";
				cout << world->player->getHoldingCard1() << endl;
				cout << endl;
				break;
			case 2:
				Sleep(1000);
				cout << "Card 2: ";
				cout << world->player->getHoldingCard2() << endl;
				cout << endl;
				break;
		}
	}


	while (Play == 'H'){
		if (first == 0){
			Sleep(1000);
			system("cls");
		}

		if (first == 0){
			cout << "You have " << world->player->getHandSize() << " cards." << endl;
			cout << endl;
			for (int i = 1; i <= world->player->getHandSize(); i++){
				switch (i){
				case 1:
					Sleep(1000);
					cout << "Card 1: ";
					cout << world->player->getHoldingCard1() << endl;
					cout << endl;
					break;
				case 2:
					Sleep(1000);
					cout << "Card 2: ";
					cout << world->player->getHoldingCard2() << endl;
					cout << endl;
					break;
				case 3:
					Sleep(1000);
					cout << "Card 3: ";
					cout << world->player->getHoldingCard3() << endl;
					cout << endl;
					break;
				case 4:
					Sleep(1000);
					cout << "Card 4: ";
					cout << world->player->getHoldingCard4() << endl;
					cout << endl;
					break;
				case 5:
					Sleep(1000);
					cout << "Card 5: ";
					cout << world->player->getHoldingCard5() << endl;
					cout << endl;
					break;
				case 6:
					Sleep(1000);
					cout << "Card 6: ";
					cout << world->player->getHoldingCard6() << endl;
					cout << endl;
					break;
				}
			}
		}
		Sleep(1000);
		cout << "Dealer's first card: ";
		cout << world->dealer->getHoldingCard1() << endl;
		cout << endl;
		Sleep(1000);
		//The following if statements output the player's current hand value, but three are needed in case the player has an ace of value 1, 11, or both.
		if ( (world->player->getAce() == true) && (AceValue == 11) ){
			cout << "The value of your hand is: " << world->player->getHandValue() << " or " << world->player->getHandValue() + 10 << endl;
		}
		if ( (world->player->getAce() == true) && (AceValue == 1) ){
			cout << "The value of your hand is: " << world->player->getHandValue() << endl;
		}
		if (world->player->getAce() == false){
			cout << "The value of your hand is: " << world->player->getHandValue() << endl;
		}
		cout << endl;
		Sleep(3000);
		for(int i = 0; i < 1;) {
			cout << "Would you like to Hit or Stand? (H/S) ";
			cin >> Play;
			cout << endl;
			if (Play == 'h'){
				Play = 'H';
				i = 1;
			}
			if (Play == 's'){
				Play  = 'S';
				i = 1;
			}
			if ( (Play != 'H') &&  (Play != 'S') ){
				cout << "You can only choose H or hit or S or Stand" << endl;
				
			}
			if ( (Play == 'H') ||  (Play == 'S') ){
				i = 1;
			}
		}
		if ( (Play == 'S') && (world->player->getAce() == true) && (AceValue == 11) ){
			cout << "Your ace value will be 11 from now on because you stand." << endl;
			cout << endl;
			world->player->setHandValue(world->player->getHandValue() + 10);
		}

		int currentCard;


		//The following adds a card to the player's hand, and is dependent upon how many cards he currently has.
		if (Play == 'H'){
			currentCard = world->deck->PickCard();
			if (world->player->getHandSize() == 2){
				world->player->setHoldingCard3(world->deck->CardFace(currentCard));
				world->player->setAce(world->player->getCardValue());
			}
			if (world->player->getHandSize() == 3){
				world->player->setHoldingCard4(world->deck->CardFace(currentCard));
				world->player->setAce(world->player->getCardValue());
			}
			if (world->player->getHandSize() == 4){
				world->player->setHoldingCard5(world->deck->CardFace(currentCard));
				world->player->setAce(world->player->getCardValue());
			}
			if (world->player->getHandSize() == 5){
				world->player->setHoldingCard6(world->deck->CardFace(currentCard));
				world->player->setAce(world->player->getCardValue());
			}
			world->player->setCardValue(world->deck->CardFace(currentCard));
			world->player->setHandValue(world->player->getCardValue() + world->player->getHandValue());
			world->player->setHandSize(world->player->getHandSize() + 1);


			//The following code checks to see if the player is bust. It is complicated because of the possibility of the player having an ace.
			if(world->player->getAce() == true){

				if (world->player->getHandValue() + 10 > 21){

					if ((world->player->getHandValue()) > 21){
						Sleep(1000);
						cout << "You are bust!!" << endl;
						Sleep(2000);
						Play = 'S';
						manager.setState(new ResultState(&manager, world));
						manager.update();
					}
					else{

						if (AceValue == 11){
							Sleep(1000);
							cout << "Next card makes you bust if your ace has a value of 11 therefore " << endl;
							cout << "your ace's value is forced to be 1." << endl;
							Sleep(6000);
							AceValue = 1;
							Play = 'H';
						}
					}
				}
			}
			if(world->player->getAce() == false){

				if (world->player->getHandValue() > 21){
					if (world->player->getHandSize() == 3){
						cout << "Card 3: ";
						cout << world->player->getHoldingCard3() << endl;
					}
					if (world->player->getHandSize() == 4){
						cout << "Card 4: ";
						cout << world->player->getHoldingCard4() << endl;
					}
					if (world->player->getHandSize() == 5){
						cout << "Card 5: ";
						cout << world->player->getHoldingCard5() << endl;
					}
					if (world->player->getHandSize() == 6){
						cout << "Card 6: ";
						cout << world->player->getHoldingCard6() << endl;
					}
					Sleep(1000);
					cout << endl;
					cout << "You are bust!!" << endl;
					cout << endl;
					Sleep(2000);
					Play = 'S';
					manager.setState(new ResultState(&manager, world));
					manager.update();
				}
			}
		}
 		else{
			Play = 'S';
		}
		first = 0;
	}

	//This if statement is needed because if the player goes bust, the dealer state never runs and therefore when the result state ends, it returns to here
	//at which point the dealer state would run, which is incorrect, this checks to see if the result state has been run yet.
	if (world->Finish == 0){
		Sleep(5000);
		cout << "It is now the dealer's turn." << endl;

		manager.setState(new DealerState(&manager, world));

		manager.update();
	}
	
}