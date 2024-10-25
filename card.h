#ifndef CARD_H
#define CARD_H

#include <ostream>
#include <string>

class Card
{
public:
    enum class Rank { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
    enum class Suit { Hearts, Diamonds, Clubs, Spades };

    Card(Rank rank, Suit suit);

    std::string getName() const;

    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    // Тут буде метод для зміни скіна згодом
private:
    Rank rank;
    Suit suit;
};

#endif // CARD_H
