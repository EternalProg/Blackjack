#ifndef DEALER_H
#define DEALER_H

#include <card.h>
#include <player.h>

class Dealer : public Player
{
public:
    Dealer();

    bool shouldStand() const;
    const Card &getHiddenCard() const;

private:
    bool hasHiddenCard = false;
};

#endif // DEALER_H
