#include <string>
#include <iostream>

#include "../headers/Blackjack.h"


Blackjack::Hand::Hand(std::string playerName)
	: m_playerName{playerName}
{
	//reserve space for the cards to be drawn
	m_cards.reserve(averageCardsAtEndOfGame);
}

//Discards entire hand down to 0
std::vector<CgCore::Card> Blackjack::Hand::discardHand()
{
	std::vector<CgCore::Card> copyOfHand{ m_cards };
	m_cards.resize(0);
	return copyOfHand;
}

bool Blackjack::Hand::isBust()
{
	int score{ 0 };
	for (auto& c : m_cards) {
		score += cardScores[c.face()];
	}
	if (score > scoreToWin) {
		m_isBust = true;
	}
	else {
		m_isBust = false;
	}
	return m_isBust;
}

int Blackjack::Hand::calculateScore()
{
	//Check to see if there are any aces in the hand
	bool acesInHand{ false };
	for (auto& c : m_cards) {
		if (c.face() == CgCore::ace) {
			acesInHand = { true };
		}
	}
	//We are using a vector to account for the fact that each ace can have two different values
	//If I'm using a vector  from the start, do I need to check for aces in advance?
	std::vector<int> score{ 0 };
	if (!acesInHand) {
		for (auto& c : m_cards) {
			score[0] += cardScores[c.face()];
		}
	}
	else {

	}
}