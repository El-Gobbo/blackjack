#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>

#include "CgCore.h"



namespace Blackjack {
	constexpr int scoreToWin{ 21 };

	constexpr int subtractScorePerAce{ 10 };
	constexpr int averageCardsAtEndOfGame{ 3 };

	constexpr std::array<int, CgCore::max_faces> cardScores{ 11,2,3,4,5,6,7,8,9,10,10,10,10 };
	static_assert(std::size(cardScores) == CgCore::max_faces, "cardScores array not the same length as Faces enum");

	class Hand {
	public:
		//Constructors
		Hand(std::string playerName);

		//Getters
		const std::string& playerName() const { return m_playerName; }
		const std::vector<CgCore::Card>& cards() const { return m_cards; }
		const int score() const { return m_score; }
		bool isStanding() const { return m_isStanding; }

		//Other Functions
		// Gets rid of all cards in hand for the next round
		std::vector<CgCore::Card> discardHand();
		// Calculates/updates the score
		void updateScore();
		//Draws 1 card from the parameterised deck
		void drawFrom(CgCore::Deck& deck);
		// Prints cards in m_cards
		void printHand() const;

	private:
		std::string m_playerName;
		std::vector<CgCore::Card> m_cards;
		int m_score{ 0 };
		int m_acesCount{ 0 };
		bool m_isStanding{ false };
	};

	// Game logic
	void playRound();
}

#endif