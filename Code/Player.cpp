#include "Player.h"
#include "StateManager.h"
#include "State.h"


Player::Player(World* _world){
	m_world = _world;
}


Player::~Player(void){
}

int Player::getHandSize(){
	return HandSize;
}

void Player::setHandSize(int a){
	HandSize = a;
}

string Player::getName(){
	return Name;
}

void Player::setName(string N){
	Name = N;
}

void Player::setHoldingCard1(string c){
	HoldingCard1[2] = c;
}

string Player::getHoldingCard1(){
	return HoldingCard1[2];
}

void Player::setHoldingCard2(string c){
	HoldingCard2[2] = c;
}

string Player::getHoldingCard2(){
	return HoldingCard2[2];
}

void Player::setHoldingCard3(string c){
	HoldingCard3[2] = c;
}

string Player::getHoldingCard3(){
	return HoldingCard3[2];
}

void Player::setHoldingCard4(string c){
	HoldingCard4[2] = c;
}

string Player::getHoldingCard4(){
	return HoldingCard4[2];
}

void Player::setHoldingCard5(string c){
	HoldingCard5[2] = c;
}

string Player::getHoldingCard5(){
	return HoldingCard5[2];
}

void Player::setHoldingCard6(string c){
	HoldingCard6[2] = c;
}

string Player::getHoldingCard6(){
	return HoldingCard6[2];
}

void Player::setCardValue(string c){

	//This function sets the value of the card depending on what the card is.

	if ( (c == "AC") || (c == "AD") || (c == "AH") || (c == "AS") ){
		Cardvalue = 1; //The default value of an ace is 1 even though it can also be 11.
					  //This is made up for later in the code when deciding what value it should be.
	}
	if ( (c == "2C") || (c == "2D") || (c == "2H") || (c == "2S") ){
		Cardvalue = 2;
	}
	if ( (c == "3C") || (c == "3D") || (c == "3H") || (c == "3S") ){
		Cardvalue = 3;
	}
	if ( (c == "4C") || (c == "4D") || (c == "4H") || (c == "4S") ){
		Cardvalue = 4;
	}
	if ( (c == "5C") || (c == "5D") || (c == "5H") || (c == "5S") ){
		Cardvalue = 5;
	}
	if ( (c == "6C") || (c == "6D") || (c == "6H") || (c == "6S") ){
		Cardvalue = 6;
	}
	if ( (c == "7C") || (c == "7D") || (c == "7H") || (c == "7S") ){
		Cardvalue = 7;
	}
	if ( (c == "8C") || (c == "8D") || (c == "8H") || (c == "8S") ){
		Cardvalue = 8;
	}
	if ( (c == "9C") || (c == "9D") || (c == "9H") || (c == "9S") ){
		Cardvalue = 9;
	}
	if ( (c == "10C") || (c == "10D") || (c == "10H") || (c == "10S") ){
		Cardvalue = 10;
	}
	if ( (c == "JC") || (c == "JD") || (c == "JH") || (c == "JS") ){
		Cardvalue = 10;
	}
	if ( (c == "QC") || (c == "QD") || (c == "QH") || (c == "QS") ){
		Cardvalue = 10;
	}
	if ( (c == "KC") || (c == "KD") || (c == "KH") || (c == "KS") ){
		Cardvalue = 10;
	}
}

int Player::getCardValue(){
	return Cardvalue;
}

void Player::setHandValue(int a){
	Handvalue = a;
}

int Player::getHandValue(){
	return Handvalue;
}

void Player::setAce(int a){
	if (a == 1){
		ace = true;
	}
	if ( (ace != true) && (a != 1) ){
		ace = false;
	}
}

bool Player::getAce(){
	return ace;
}