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

size_t getCardScore(const Card &card)
{
    {
        switch (card.getRank()) {
        case Card::Rank::Two:
            return 2;
        case Card::Rank::Three:
            return 3;
        case Card::Rank::Four:
            return 4;
        case Card::Rank::Five:
            return 5;
        case Card::Rank::Six:
            return 6;
        case Card::Rank::Seven:
            return 7;
        case Card::Rank::Eight:
            return 8;
        case Card::Rank::Nine:
            return 9;
        case Card::Rank::Ten:
            return 10;
        case Card::Rank::Jack:
            return 10;
        case Card::Rank::Queen:
            return 10;
        case Card::Rank::King:
            return 10;
        case Card::Rank::Ace:
            return 0;
        default:
            return 0;
        }
    }
}
