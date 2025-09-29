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

void Blackjack::Hand::updateScore()
{
	m_score += cardScores[m_cards.back().face()];
	if (m_score > scoreToWin && m_acesCount > 0) {
		m_score -= subtractScorePerAce;
		--m_acesCount;
	}
}

// Draw 1 card from the relevant deck
void Blackjack::Hand::drawFrom(CgCore::Deck& deck)
{
	// Push the card removed from the deck m_cards
	m_cards.push_back(deck.deal());
	// If the card is an ace, increment the aces counter
	if (m_cards.back().face() == CgCore::ace)
		++m_acesCount;
	updateScore();
}

void Blackjack::Hand::printHand() const
{
	std::cout << m_playerName << "'s hand contains: ";
	bool semicolon{ false };
	for (const auto& c : m_cards) {
		if (semicolon)
			std::cout << "; ";
		c.printCard();
	}
	std::cout << ".\n";
}

/* 
Main game logic below!
*/

void Blackjack::playRound()
{
	CgCore::Deck deck{};

	Hand dealer{ "The Dealer" };
	std::cout << "Enter Your name: ";
	std::string playerName{};
	// TODO: add checking for input errors here
	std::cin >> playerName;
	Hand player1{ playerName };

	// draw Initial cards
	dealer.drawFrom(deck);
	player1.drawFrom(deck);
	player1.drawFrom(deck);

	while (player1.score() <= scoreToWin && !player1.isStanding()) {
		dealer.printHand();
		player1.printHand();
		std::cout << "Hit(0) or stand(1)? ";
		//TODO: definitely needs input control, and tbh some way of inputting hit or stand that's better than this.
		bool stand{};
		std::cin >> stand;
		if (!stand) {
			player1.drawFrom(deck);
			player1.updateScore();
		}
	}
}