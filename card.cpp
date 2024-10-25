#include "card.h"

//Card::Card() {}

Card::Card(Rank rank, Suit suit)
    : rank(rank)
    , suit(suit)
{}

std::string Card::getName() const
{
    static const std::string rankNames[] = {"Two",
                                            "Three",
                                            "Four",
                                            "Five",
                                            "Six",
                                            "Seven",
                                            "Eight",
                                            "Nine",
                                            "Ten",
                                            "Jack",
                                            "Queen",
                                            "King",
                                            "Ace"};
    static const std::string suitNames[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    return rankNames[static_cast<int>(rank)] + "#" + suitNames[static_cast<int>(suit)];
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
    out << card.getName();
    return out;
}
