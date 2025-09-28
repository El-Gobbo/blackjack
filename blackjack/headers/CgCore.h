#ifndef CGCORE_H
#define CGCORE_H

#include <array>
#include <string_view>
#include <vector>

namespace CgCore {
	enum Suit {
		spades,
		hearts,
		diamonds,
		clubs,
		max_suits
	};
	constexpr std::array<std::string_view, max_suits> suits{
"spades", "hearts", "diamonds", "clubs"
	};
	static_assert(suits.size() == max_suits, "Error: suits array does not match Suit enum count");

	enum Face {
		ace,
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		max_faces
	};
	constexpr std::array<std::string_view, max_faces> faces{
		"ace", "two", "three", "four", "five",
		"six", "seven", "eight", "nine", "ten",
		"jack", "queen", "king"
	};
	static_assert(faces.size() == max_faces, "Error: faces array does not match Face enum count");

	constexpr std::size_t deckSize{ 52 };

	class Card {
	public:
		Suit suit() { return m_suit; }
		Face face() { return m_face; }
	private:
		Suit m_suit{};
		Face m_face{};
	};

	class Deck {
	public:
		Deck();

		void shuffle();
		Card deal();
		void returnToDeck(std::vector<Card> cardsToReturn);
	private:
		std::array<Card, deckSize> m_cards{};
	};
}

#endif