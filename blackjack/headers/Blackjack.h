#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>

#include "CgCore.h"

namespace Blackjack {
	class Hand {
	public:
		//Constructors
		Hand(std::string playerName);

		//Getters
		const std::string& getPlayerName() const { return m_playerName; }
		const std::vector<CgCore::Card>& getCards() const { return m_cards; }
		bool getIsDealer() const { return m_isDealer; }
		bool getIsStanding() const { return m_isStanding; }

		//Setters
		void setIsDealer(bool isDealer) { m_isDealer = isDealer; }
		void setIsBust(bool isBust) { m_isBust = isBust; }

		//Other Functions
		void draw(CgCore::Card card);
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