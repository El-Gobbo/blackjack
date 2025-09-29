#include <iostream>
#include <algorithm>

#include "../headers/CgCore.h"
#include "../headers/Rand.h"
//MEMBER FUNCTIONS of CgCore::Card
CgCore::Card::Card(CgCore::Suit suit, CgCore::Face face)
	: m_suit{suit}
	, m_face{face}
{}

void CgCore::Card::printCard() const
{
	std::cout << "the " << faceSV[m_face] << " of " << suitSV[m_suit];
}


//MEMBER FUNCTIONS of CgCore::Deck
CgCore::Deck::Deck()
{
	m_cards.reserve(deckSize);
	for (Suit s : suits) {
		for (Face f : faces) {
			m_cards.push_back(Card{ s, f });
		}
	}
	shuffle();
}

//fisher-yates shuffle algorithm
void CgCore::Deck::shuffle()
{
	std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
}

// Deal out individual cards from the top of the deck
CgCore::Card CgCore::Deck::deal()
{
	CgCore::Card toDeal{ m_cards.back() };
	m_cards.pop_back();
	return toDeal;
}

// Return vector of cards to the deck
void CgCore::Deck::returnToDeck(std::vector<CgCore::Card> cardsToReturn)
{
	for (auto& c : cardsToReturn) {
		m_cards.push_back(c);
	}
	shuffle();
}

void CgCore::Deck::printDeck()
{
	std::cout << "The cards in this deck, in order, are: \n";
	for (auto& c : m_cards) {
		c.printCard();
		std::cout<<".\n";
	}
}