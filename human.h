#ifndef HUMAN_H
#define HUMAN_H

#include <player.h>

class Human : public Player
{
public:
    Human(int initialBalance);

    void increaseBet(int amount);
    void decreaseBet(int amount);

    int getBalance() const;

    int getBet() const;

    void resetBet();

    void updateBalance(int amount);
private:
    int balance;
    static constexpr int minBet = 10;
    int bet = minBet;
};

#endif // HUMAN_H
