#include "../headers/CgCore.h"
#include "../headers/Rand.h"
//MEMBER FUNCTIONS of CgCore::Card
CgCore::Card::Card(CgCore::Suit suit, CgCore::Face face)
	: m_suit{suit}
	, m_face{face}
{}


//MEMBER FUNCTIONS of CgCore::Deck
CgCore::Deck::Deck()
{
	m_cards.reserve(static_cast<std::size_t>(deckSize));
	for (auto& s : suits) {
		for (auto& f : faces) {
			m_cards.push_back({ s, f });
		}
	}
}

//fisher-yates shuffle algorithm
void CgCore::Deck::shuffle()
{
	//Initialise I to the final index in the m_cards vector
	for (int i{ static_cast<int>(std::size(m_cards)) - 1}; i > 0; --i) {
		int toSwap{ Random::get(0,i) };
		if (!(toSwap == i)) {
			Card copyOfI{ m_cards[i] };
			m_cards[i] = m_cards[toSwap];
			m_cards[toSwap] = copyOfI;
		}
	}
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