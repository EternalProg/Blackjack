#ifndef CARD_H
#define CARD_H

#include <ostream>
#include <string>

constexpr size_t getCardScore(const Card &card)
{
    if (card.getN)
        switch (card.getRank()) {
        case Card::Rank::Two:
            return 2;
        case Card::Rank::Three:
            return 3;
        case Card::Rank::Four:
            return 4;
        case Card::Rank::Five:
            return 5;
        case Card::Rank::Six:
            return 6;
        case Card::Rank::Seven:
            return 7;
        case Card::Rank::Eight:
            return 8;
        case Card::Rank::Nine:
            return 9;
        case Card::Rank::Ten:
            return 10;
        case Card::Rank::Jack:
            return 10;
        case Card::Rank::Queen:
            return 10;
        case Card::Rank::King:
            return 10;
        default:
            return 0;
        }
}

class Card
{
public:
    enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
    enum class Suit { Hearts, Diamonds, Clubs, Spades };

    Card(Rank rank, Suit suit);

    std::string getName() const;

    Rank getRank() { return rank; }
    Suit getSuit() { return suit; }

    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    // Тут буде метод для зміни скіна згодом
private:
    Rank rank;
    Suit suit;
};

#endif // CARD_H
