#include "dealer.h"

Dealer::Dealer() {}

bool Dealer::shouldStand() const
{
    return getScore() >= 17;
}

size_t Dealer::getHiddenCardScore()
{
    return getCardScore(hand[0]);
}

void Dealer::setHasHiddenCard(bool flag)
{
    hasHiddenCard_ = flag;
}

bool Dealer::hasHiddenCard() const
{
    return hasHiddenCard_;
}
