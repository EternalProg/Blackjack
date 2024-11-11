#ifndef HUMAN_H
#define HUMAN_H

#include <player.h>

class Human : private Player
{
public:
    Human(int initialBalance);

    void increaseBet(int amount);
    void decreaseBet(int amount);

    int getBalance() const;

    int getBet() const;

    // Скидання ставки (на новий раунд)
    void resetBet();

    // Додавання або віднімання грошей в залежності від результату гри
    void updateBalance(int amount);
private:
    int balance;
    int bet;
};

#endif // HUMAN_H
