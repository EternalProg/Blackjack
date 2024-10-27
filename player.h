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

    size_t getScore() const;

protected:
    QVector<Card> hand;
    size_t scoreWithoutAces = 0;
    size_t countOfAces = 0;
};

#endif // PLAYER_H
