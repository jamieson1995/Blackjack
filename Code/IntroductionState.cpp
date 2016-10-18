#include "IntroductionState.h"
#include "StateManager.h"

#include <iostream>

IntroductionState::IntroductionState(StateManager* manager, World* world) : State(manager)
{
	// Constructor
	this->world = world;
}

void IntroductionState::update()
{
	Sleep(1000);
	bool check = false;
	string Name;

	Sleep(1000);
	cout << "Welcome to Blackjack" << endl;
	Sleep(1000);
	cout << endl;
	cout << "Please enter your name: ";
	cin >> Name;
	cout << endl;

	world->player->setName(Name);

	Sleep(1000);
	cout << "Dealing cards......" << endl;
	cout << endl;
	Sleep(2000);
	int currentCard;

	world->player->setHandValue(0);

		//This sets the first 2 cards for the player.
	currentCard = world->deck->PickCard();
	world->player->setCardValue(world->deck->CardFace(currentCard));
	world->player->setHandValue(world->player->getCardValue() + world->player->getHandValue());
	world->player->setHoldingCard1(world->deck->CardFace(currentCard));
	world->player->setAce(world->player->getCardValue());
	currentCard = world->deck->PickCard();
	world->player->setCardValue(world->deck->CardFace(currentCard));
	world->player->setHandValue(world->player->getCardValue() + world->player->getHandValue());
	world->player->setHoldingCard2(world->deck->CardFace(currentCard));
	world->player->setAce(world->player->getCardValue());

	world->dealer->setHandValue(0);

		//This sets the first 2 cards for the dealer.
	currentCard = world->deck->PickCard();
	world->dealer->setCardValue(world->deck->CardFace(currentCard));
	world->dealer->setHandValue(world->dealer->getCardValue() + world->dealer->getHandValue());
	world->dealer->setHoldingCard1(world->deck->CardFace(currentCard));
	world->dealer->setAce(world->dealer->getCardValue());
	currentCard = world->deck->PickCard();
	world->dealer->setCardValue(world->deck->CardFace(currentCard));
	world->dealer->setHandValue(world->dealer->getCardValue() + world->dealer->getHandValue());
	world->dealer->setHoldingCard2(world->deck->CardFace(currentCard));
	world->dealer->setAce(world->dealer->getCardValue());

	world->player->setHandSize(2);
	world->dealer->setHandSize(2);

	manager.setState(new PlayState(&manager, world));

	manager.update();

}