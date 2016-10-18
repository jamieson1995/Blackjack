#include "DealerState.h"


DealerState::DealerState(StateManager* manager, World* world) : State(manager)
{
	this->world = world;
}

void DealerState::update(){

	char Play = 'H';

	int AceValue = 11;

	while (Play == 'H'){
		Sleep(1000);
		system("cls");
		cout << "The dealer has " << world->dealer->getHandSize() << " cards."<< endl;
		cout << endl;
		for (int i = 1; i <= world->dealer->getHandSize(); i++){
			switch (i){
			case 1:
				Sleep(1000);
				cout << "Card 1: ";
				cout << world->dealer->getHoldingCard1() << endl;
				cout << endl;
				break;
			case 2:
				Sleep(1000);
				cout << "Card 2: ";
				cout << world->dealer->getHoldingCard2() << endl;
				cout << endl;
				break;
			case 3:
				Sleep(1000);
				cout << "Card 3: ";
				cout << world->dealer->getHoldingCard3() << endl;
				cout << endl;
				break;
			case 4:
				Sleep(1000);
				cout << "Card 4: ";
				cout << world->dealer->getHoldingCard4() << endl;
				cout << endl;
				break;
			case 5:
				Sleep(1000);
				cout << "Card 5: ";
				cout << world->dealer->getHoldingCard5() << endl;
				cout << endl;
				break;
			case 6:
				Sleep(1000);
				cout << "Card 6: ";
				cout << world->dealer->getHoldingCard6() << endl;
				cout << endl;
				break;
			}
		}


		//The following if statements output the dealer's current hand value, but three are needed in case the dealer has an ace of value 1, 11, or both.
		Sleep(1000);
		if ( (world->dealer->getAce() == true) && (AceValue == 11) ){
			cout << "The value of the dealer's hand is: " << world->dealer->getHandValue() << " or " << world->dealer->getHandValue() + 10 << endl;
		}
		if ( (world->dealer->getAce() == true) && (AceValue == 1) ){
			cout << "The value of the dealer's hand is: " << world->dealer->getHandValue() << endl;
		}
		if (world->dealer->getAce() == false){
			cout << "The value of the dealer's hand is: " << world->dealer->getHandValue() << endl;
		}
		cout << endl;
		Sleep(3000);

		//This piece of code is where the dealer 'chooses' if he should hit or stand
		if (world->dealer->getAce() == false){
			if (world->dealer->getHandValue() <= 17){
				cout << "The dealer hits! " << endl;
				cout << endl;
				Play = 'H';
			}
			if (world->dealer->getHandValue() > 17){
				cout << "The dealer stands." << endl;
				cout << endl;
				Play = 'S';
				}
		}
		if (world->dealer->getAce() == true){
			if (AceValue == 11){
				if (world->dealer->getHandValue() + 10 <= 17){
				cout << "The dealer hits." << endl;
				cout << endl;
				Play = 'H';
				}
				else if (world->dealer->getHandValue() + 10 > 17){
				cout << "The dealer stands." << endl;
				cout << endl;
				Play = 'S';
				world->dealer->setHandValue(world->dealer->getHandValue() + 10);
				}
			}
			
			if (AceValue == 1){
				if (world->dealer->getHandValue() < 17){
					cout << "The dealer hits." << endl;
					cout << endl;
					Play = 'H';
				}
				if (world->dealer->getHandValue() >= 17){
					cout << "The dealer sticks." << endl;
					cout << endl;
					Play = 'S';
				}
			}
		}

		int currentCard;

		Sleep(1000);

		//The following adds a card to the dealer's hand, and is dependent upon how many cards he currently has.
		if (Play == 'H'){
			currentCard = world->deck->PickCard();
			if (world->dealer->getHandSize() == 2){
				world->dealer->setHoldingCard3(world->deck->CardFace(currentCard));
				world->dealer->setAce(world->dealer->getCardValue());
			}
			if (world->dealer->getHandSize() == 3){
				world->dealer->setHoldingCard4(world->deck->CardFace(currentCard));
				world->dealer->setAce(world->dealer->getCardValue());
			}
			if (world->dealer->getHandSize() == 4){
				world->dealer->setHoldingCard5(world->deck->CardFace(currentCard));
				world->dealer->setAce(world->dealer->getCardValue());
			}
			if (world->dealer->getHandSize() == 5){
				world->dealer->setHoldingCard6(world->deck->CardFace(currentCard));
				world->dealer->setAce(world->dealer->getCardValue());
			}
			world->dealer->setCardValue(world->deck->CardFace(currentCard));
			world->dealer->setHandValue(world->dealer->getCardValue() + world->dealer->getHandValue());
			world->dealer->setHandSize(world->dealer->getHandSize() + 1);


			//The following code checks to see if the dealer is bust. It is complicated because of the possibility of the dealer having an ace.
			if(world->dealer->getAce() == true){
				if ((world->dealer->getHandValue() + 10) > 21){
					if(world->dealer->getHandValue() > 21){
							if (world->dealer->getHandSize() == 3){
							cout << "Card 3: ";
							cout << world->dealer->getHoldingCard3() << endl;
						}
						if (world->dealer->getHandSize() == 4){
							cout << "Card 4: ";
							cout << world->dealer->getHoldingCard4() << endl;
						}
						if (world->dealer->getHandSize() == 5){
							cout << "Card 5: ";
							cout << world->dealer->getHoldingCard5() << endl;
						}
						if (world->dealer->getHandSize() == 6){
							cout << "Card 6: ";
							cout << world->dealer->getHoldingCard6() << endl;
						}
						Sleep(1000);
						cout << "The dealer is bust!!" << endl;
						cout << endl;
						Play = 'S';
					}
					if (world->dealer->getHandValue() <= 21){
							Sleep(1000);
							cout << "The dealer's next card will make him bust if the value of his" << endl;
							cout << "ace is 11 thereforethe value of him ace will always be 1 for now on." << endl;
							cout << endl;
							Sleep(6000);
							AceValue = 1;
							Play = 'H';
					}
				} 
			}
			if (world->dealer->getAce() == false){
				if(world->dealer->getHandValue() > 21){
					cout << "The dealer is bust!!" << endl;
					cout << endl;
					Play = 'S';
				}
			}
		}
		else{
			Play = 'S';
		}
	}

	manager.setState(new ResultState(&manager, world));

	manager.update();
}