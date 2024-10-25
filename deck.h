#ifndef DECK_H
#define DECK_H

#include <QVector>
#include <card.h>
#include <iostream>

class Deck
{
public:
    Deck();
    void shuffle();
    Card draw();
    void printCards() {
        for(int r = 0; r < cards.size(); ++r) {
            std::cout << cards[r] << " ";
        }
    }
private:
    QVector<Card> cards;
};

#endif // DECK_H
