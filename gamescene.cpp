#include "gamescene.h"

GameScene::GameScene(const QPointF &position, QMainWindow *parent)
    : QGraphicsScene(parent)
    , playerInfo(std::make_unique<PlayerInfo>())
{
    view = std::make_unique<QGraphicsView>(this);
    view->setScene(this);
    view->setFixedSize(600, 200);
    view->setRenderHint(QPainter::Antialiasing);
    playerInfo->pos = position;
}

QGraphicsView *GameScene::getView() const
{
    return view.get();
}

void GameScene::addCardToPlayer(const Card &card)
{
    auto cardView = std::make_unique<CardView>(card);
    QPointF position = playerInfo->pos + QPointF(cardOffsetX * playerInfo->cardViews.size(), 0);
    cardView->setPos(position);
    addItem(cardView.get());
    playerInfo->cardViews.push_back(std::move(cardView));
    updateView();
}

void GameScene::addHiddenCardToPlayer(const Card &card)
{
    auto cardView = std::make_unique<CardView>(card);
    QPointF position = playerInfo->pos + QPointF(cardOffsetX * playerInfo->cardViews.size(), 0);
    cardView->setPos(position);
    cardView->showFront();
    addItem(cardView.get());
    playerInfo->cardViews.push_back(std::move(cardView));
    updateView();
}

void GameScene::clearScene()
{
    for (auto &cardView : playerInfo->cardViews) {
        removeItem(cardView.get());
    }
    playerInfo->cardViews.clear();
}

void GameScene::updateView()
{
    view->update();
}

void GameScene::showFrontCard(const Card &card)
{
    for (const auto &cardView : playerInfo->cardViews) {
        if (&cardView->getCard() == &card) {
            cardView->showFront();
        }
    }
}

void GameScene::showBackCard(const Card &card)
{
    for (const auto &cardView : playerInfo->cardViews) {
        if (&cardView->getCard() == &card) {
            cardView->showBack();
        }
    }
}
