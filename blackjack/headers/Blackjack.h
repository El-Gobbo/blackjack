#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>

#include "CgCore.h"

namespace Blackjack {
	constexpr int scoreToWin{ 21 };
	constexpr int averageCardsAtEndOfGame{ 3 };
	constexpr std::array<int, CgCore::max_faces> cardScores{ 1,2,3,4,5,6,7,8,9,10,10,10,10 };
	static_assert(std::size(cardScores) == CgCore::max_faces, "cardScores array not the same length as Faces enum");

	class Hand {
	public:
		//Constructors
		Hand(std::string playerName);

		//Getters
		const std::string& playerName() const { return m_playerName; }
		const std::vector<CgCore::Card>& cards() const { return m_cards; }
		bool isDealer() const { return m_isDealer; }
		bool isStanding() const { return m_isStanding; }

		//Setters
		void draw(CgCore::Card card) { m_cards.push_back(card); }
		void setIsDealer(bool isDealer) { m_isDealer = isDealer; }
		void setIsBust(bool isBust) { m_isBust = isBust; }

		//Other Functions
		std::vector<CgCore::Card> discardHand();
		bool isBust();
		int calculateScore();

	private:
		std::string m_playerName;
		std::vector<CgCore::Card> m_cards;
		bool m_isDealer{ false };
		bool m_isBust{ false };
		bool m_isStanding{ false };
	};
}

#endif