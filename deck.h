#ifndef DECK_H
#define DECK_H

#include <QVector>
#include <card.h>

class Deck
{
public:
    Deck();
    void shuffle();
    Card draw() noexcept;
    void printCards() noexcept;
    bool isEmpty() const noexcept;

private:
    QVector<Card> cards;
    size_t i = 0;
};

#endif // DECK_H
