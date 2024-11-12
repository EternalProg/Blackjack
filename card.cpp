#include "card.h"

//Card::Card() {}

Card::Card(Rank rank, Suit suit)
    : rank(rank)
    , suit(suit)
{}

Card::Card() {}

Card::Rank Card::getRank() const
{
    return rank;
}

Card::Suit Card::getSuit() const
{
    return suit;
}

QString Card::getFrontSkin() const
{
    return cardSkin.frontSkin;
}

QString Card::getBackSkin() const
{
    return cardSkin.backSkin;
}

void Card::setSkin(const QString &front, const QString &back)
{
    cardSkin.frontSkin = front;
    cardSkin.backSkin = back;
}

bool Card::getIsFront() const
{
    return isFront;
}

void Card::setIsFront(bool isFront) const
{
    this->isFront = isFront;
}

size_t getCardScore(const Card &card)
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
