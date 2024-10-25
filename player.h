#ifndef PLAYER_H
#define PLAYER_H

#include <QVector>
#include <card.h>

class Player
{
public:
    Player();
    virtual ~Player() = default;

    void addCard(const Card& card);
    void clearHand();

    // розраховує та повертає загальну суму очок на руках (враховуючи правила підрахунку тузів).
    int getScore() const;
protected:
    QVector<Card> hand;
};

#endif // PLAYER_H
