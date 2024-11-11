#include "deck.h"

#include <algorithm>
#include <iostream>
#include <random>

Deck::Deck() {
    for (int r = static_cast<int>(Card::Rank::Two); r <= static_cast<int>(Card::Rank::Ace); ++r) {
        for (int s = static_cast<int>(Card::Suit::Hearts);
             s <= static_cast<int>(Card::Suit::Spades);
             ++s) {
            cards.emplace_back(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s));
        }
    }
    shuffle();
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);
    i = 0;
    // https://en.cppreference.com/w/cpp/algorithm/random_shuffle
}

Card Deck::draw() noexcept
{
    return cards[i++];
}

void Deck::printCards() const noexcept
{
    for (int r = 0; r < cards.size(); ++r) {
        std::cout << cards[r] << " ";
    }
    std::cout << std::endl;
}

bool Deck::isEmpty() const noexcept
{
    return i >= cards.size();
}
