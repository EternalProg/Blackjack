#include "human.h"

//Human::Human() {}

#include <iostream>

Human::Human(int initialBalance)
    : balance(initialBalance)
{}

void Human::increaseBet(int amount)
{
    if (bet + amount <= balance) {
        bet += amount;
    } else {
        std::cout << "You do not have enough balance to increase bet" << std::endl;
    }
}

void Human::decreaseBet(int amount)
{
    if (bet - amount < minBet) {
        std::cout << "The bet can't be less than " << minBet << std::endl;
    } else {
        bet -= amount;
    }
}

int Human::getBalance() const
{
    return balance;
}

int Human::getBet() const
{
    return bet;
}

void Human::resetBet()
{
    bet = minBet;
}

void Human::updateBalance(int amount)
{
    balance += amount;
}
