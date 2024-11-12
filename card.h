#ifndef CARD_H
#define CARD_H

#include <QString>

struct CardSkins
{
    QString frontSkin;
    QString backSkin;
};

class Card
{
public:
    enum class Rank {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };
    enum class Suit { Clubs = 1, Spades, Diamonds, Hearts };

    Card(Rank rank, Suit suit);
    Card();

    Rank getRank() const;
    Suit getSuit() const;

    QString getFrontSkin() const;
    QString getBackSkin() const;

    void setSkin(const QString &front, const QString &back);
    bool getIsFront() const;
    void setIsFront(bool isFront) const;

private:
    Rank rank;
    Suit suit;
    mutable bool isFront = true;
    CardSkins cardSkin;
};

size_t getCardScore(const Card &card);

#endif // CARD_H
