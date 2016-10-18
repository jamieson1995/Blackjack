#include "Deck.h"


Deck::Deck(World* _world){
	m_world = _world;
}


Deck::~Deck(void)
{
}



int Deck::PickCard(){
	do{
	srand(time(0));
	rand();
	cardIndex = (rand()%52 + 1); //This picks a random number, makes it between 1 and 52, then adds one to it because arrays begin at 0.
	}
	while (usedCard[cardIndex] == 0); //This is needed so that the same number cannot be picked more than once.
	usedCard[cardIndex] = 0; //Once a number has been picked, it becomes 0.
	return cardIndex;
}

void Deck::shuffleDeck(){
	for (int a = 0; a < 52; a++){ //This populates the usedCard array with values.
		usedCard[a] = a + 1;
	}
}

string Deck::CardFace(int currentCard){

	//This function creates the card face depending upon the number chosen in the Pick Card function

	string Card;
	string Suit[4] = {"C", "D", "H", "S"};
	string Value[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q","K"};
	int i, j;

	if (currentCard <= 13){
		i = 0;
	}
	if ( (13 < currentCard) && (currentCard <= 26) ){
		i = 1;
	}
	if ( (26 < currentCard) && (currentCard <= 39) ){
		i = 2;
	}
	if ( (39 < currentCard) && (currentCard <= 52) ){
		i = 3;
	}
	if ( ( currentCard == 1) || ( currentCard == 14) || ( currentCard == 27) || ( currentCard == 40) ){
		j = 0;
	}
	if ( ( currentCard == 2) || ( currentCard == 15) || ( currentCard == 28) || ( currentCard == 41) ){
		j = 1;																						 
	}																								 
	if ( ( currentCard == 3) || ( currentCard == 16) || ( currentCard == 29) || ( currentCard == 42) ){
		j = 2;																						 
	}																								 
	if ( ( currentCard == 4) || ( currentCard == 17) || ( currentCard == 30) || ( currentCard == 43) ){
		j = 3;																						 
	}																								 
	if ( ( currentCard == 5) || ( currentCard == 18) || ( currentCard == 31) || ( currentCard == 44) ){
		j = 4;																						 
	}																								 
	if ( ( currentCard == 6) || ( currentCard == 19) || ( currentCard == 32) || ( currentCard == 45) ){
		j = 5;																						 
	}																								 
	if ( ( currentCard == 7) || ( currentCard == 20) || ( currentCard == 33) || ( currentCard == 46) ){
		j = 6;																						 
	}																								 
	if ( ( currentCard == 8) || ( currentCard == 21) || ( currentCard == 34) || ( currentCard == 47) ){
		j = 7;																						 
	}																								 
	if ( ( currentCard == 9) || ( currentCard == 22) || ( currentCard == 35) || ( currentCard == 48) ){
		j = 8;
	}
	if ( ( currentCard == 10) || ( currentCard == 23) || ( currentCard == 36) || ( currentCard == 49) ){
		j = 9;
	}
	if ( ( currentCard == 11) || ( currentCard == 24) || ( currentCard == 37) || ( currentCard == 50) ){
		j = 10;
	}
	if ( ( currentCard == 12) || ( currentCard == 25) || ( currentCard == 38) || ( currentCard == 51) ){
		j = 11;
	}
	if ( ( currentCard == 13) || ( currentCard == 26) || ( currentCard == 39) || ( currentCard == 52) ){
		j = 12;
	}
	Card = Value[j] + Suit[i];
	return Card;
}

