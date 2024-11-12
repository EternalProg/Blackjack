#include "player.h"
#include <card.h>

Player::Player() {}

void Player::addCard(const Card &card)
{
    hand.push_back(card);
    size_t cardScore = getCardScore(card);

    if (cardScore == 0) {
        ++countOfAces;
    } else {
        scoreWithoutAces += cardScore;
    }
}

void Player::clearHand()
{
    hand.clear();
    scoreWithoutAces = 0;
    countOfAces = 0;
}

size_t Player::getScore() const
{
    size_t totalScore = scoreWithoutAces;
    if (countOfAces > 0) {
        if (totalScore + 11 + (countOfAces - 1) <= 21) {
            totalScore += 11 + (countOfAces - 1);
        } else {
            totalScore += countOfAces;
        }
    }
    return totalScore;
}
