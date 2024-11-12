#ifndef DEALER_H
#define DEALER_H

#include <card.h>
#include <player.h>

class Dealer : public Player
{
public:
    Dealer();

    bool shouldStand() const;
    size_t getHiddenCardScore();
    void setHasHiddenCard(bool flag);
    bool hasHiddenCard() const;

private:
    bool hasHiddenCard_ = true;
};

#endif // DEALER_H
