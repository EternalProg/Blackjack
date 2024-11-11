#include "game.h"
#include <QThread>
#include <iostream>

Game::Game(QMainWindow *parent)
    : deck(std::make_unique<Deck>())
    , dealer(std::make_unique<Dealer>())
    , human(std::make_unique<Human>(500))
{
    scenes[dealer.get()] = std::make_unique<GameScene>(QPointF(500, 200), parent);
    scenes[human.get()] = std::make_unique<GameScene>(QPointF(500, 500), parent);
}

void Game::startNewGame()
{
    if (human->getBalance() <= 0) {
        std::cout << "Game over! You have no more balance." << std::endl;
        return;
    }

    std::cout << "Starting new game..." << std::endl;
    deck->shuffle();
    human->clearHand();
    dealer->clearHand();

    humanStands = false;

    scenes[dealer.get()]->clearScene();
    scenes[human.get()]->clearScene();

    for (int i = 0; i < 2; ++i) {
        Card dealerCard = drawCard();
        Card humanCard = drawCard();

        dealer->addCard(dealerCard);

        human->addCard(humanCard);
        if (i == 0) {
            scenes[dealer.get()]->addHiddenCardToPlayer(dealerCard);
        } else {
            scenes[dealer.get()]->addCardToPlayer(dealerCard);
        }

        scenes[human.get()]->addCardToPlayer(humanCard);
    }

    std::cout << "Your score: " << human->getScore() << "\n";
    std::cout << "Dealer score: " << dealer->getScore() << "\n";

    scenes[dealer.get()]->updateView();
    scenes[human.get()]->updateView();
}

void Game::humanRound()
{
    if (!humanStands) {
        Card humanCard = drawCard();
        scenes[human.get()]->addCardToPlayer(humanCard);
        human->addCard(humanCard);
        scenes[human.get()]->updateView();

        if (human->getScore() > 21) {
            humanStands = true;
            emit resultReady();
        }
    }
}
void Game::dealerRound()
{
    if (!humanStands) {
        while (!dealer->shouldStand()) {
            QThread::sleep(1);
            Card dealerCard = drawCard();
            scenes[dealer.get()]->addCardToPlayer(dealerCard);
            dealer->addCard(dealerCard);
        }

        scenes[dealer.get()]->showFrontCard(dealer->getHiddenCard());

        emit resultReady();
        human->resetBet();
        scenes[dealer.get()]->updateView();
    }
    humanStands = true;

    if (human->getBalance() <= 0) {
        std::cout << "Game over! You have no more balance." << std::endl;
    }
}

QGraphicsScene *Game::getHumanScene() const
{
    return scenes.at(human.get()).get();
}

QGraphicsScene *Game::getDealerScene() const
{
    return scenes.at(dealer.get()).get();
}

Dealer *Game::getDealer() const
{
    return dealer.get();
}

Human *Game::getHuman() const
{
    return human.get();
}

Card Game::drawCard()
{
    return deck->draw();
}
