#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <cardview.h>
#include <memory>
#include <player.h>
#include <vector>

class GameScene : public QGraphicsScene
{
public:
    GameScene(const QPointF &position, QMainWindow *parent = nullptr);

    QGraphicsView *getView() const;

    void addCardToPlayer(const Card &card);
    void addHiddenCardToPlayer(const Card &card);
    void clearScene();
    void updateView();

    void showFrontCard(const Card &card);
    void showBackCard(const Card &card);

private:
    std::unique_ptr<QGraphicsView> view;
    struct PlayerInfo
    {
        QPointF pos;
        std::vector<std::unique_ptr<CardView>> cardViews;
    };

    std::unique_ptr<PlayerInfo> playerInfo;
    int cardOffsetX = 30;
};

#endif // GAMESCENE_H
