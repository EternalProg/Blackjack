#ifndef GAME_H
#define GAME_H

#include <dealer.h>
#include <deck.h>
#include <gamescene.h>
#include <human.h>

using namespace std;

class Game : public QObject
{
    Q_OBJECT
public:
    Game(QMainWindow *parent);
    void startNewGame();
    void playRound();
    void humanRound();
    void dealerRound();

    QGraphicsScene *getHumanScene() const;
    QGraphicsScene *getDealerScene() const;

    Dealer *getDealer() const;
    Human *getHuman() const;

signals:
    void resultReady();

private:
    Card drawCard();

    unique_ptr<Deck> deck;
    unique_ptr<Dealer> dealer;
    unique_ptr<Human> human;

    bool humanStands = false;

    std::unordered_map<Player *, unique_ptr<GameScene>> scenes;
};

#endif // GAME_H
