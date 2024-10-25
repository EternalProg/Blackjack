#ifndef DEALER_H
#define DEALER_H

#include <player.h>
#include <card.h>

class Dealer : public Player
{
public:
    Dealer();

    // Метод для автоматичної гри дилера (логіка добору карт)
    void playTurn();

    bool shouldStand() const;

    // Повертає одну карту дилера, яка буде схована
    const Card& getHiddenCard() const;

private:
    bool hasHiddenCard;
};

#endif // DEALER_H
