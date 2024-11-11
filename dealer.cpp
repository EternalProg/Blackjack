#include "dealer.h"

Dealer::Dealer() {}

bool Dealer::shouldStand() const
{
    return getScore() >= 17;
}

const Card &Dealer::getHiddenCard() const
{
    return hand.front();
}
