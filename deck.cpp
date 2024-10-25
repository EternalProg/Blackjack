#include "deck.h"

Deck::Deck() {
    static const Card::Rank ranks[] = {Card::Rank::Two,
                                       Card::Rank::Three,
                                       Card::Rank::Four,
                                       Card::Rank::Five,
                                       Card::Rank::Six,
                                       Card::Rank::Seven,
                                       Card::Rank::Eight,
                                       Card::Rank::Nine,
                                       Card::Rank::Ten,
                                       Card::Rank::Jack,
                                       Card::Rank::Queen,
                                       Card::Rank::King,
                                       Card::Rank::Ace};

    static const Card::Suit suits[] = {Card::Suit::Hearts,
                                       Card::Suit::Diamonds,
                                       Card::Suit::Clubs,
                                       Card::Suit::Spades};

    for (auto rank : ranks) {
        for (auto suit : suits) {
            cards.emplace_back(rank, suit);
        }
    }
}
