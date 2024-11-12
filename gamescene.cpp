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

void GameScene::addCardToPlayer(const Card &card, const QPointF &deckPos)
{
    auto cardView = std::make_unique<CardView>(card);
    QPointF position = playerInfo->pos + QPointF(cardOffsetX * playerInfo->cardViews.size(), 0);
    cardView->setPos(position);
    addItem(cardView.get());
    cardView->animateTo(deckPos, position);
    playerInfo->cardViews.push_back(std::move(cardView));

    QRectF sceneRect = itemsBoundingRect();
    setSceneRect(sceneRect);
    view->fitInView(sceneRect, Qt::KeepAspectRatio);

    updateView();
}

void GameScene::addHiddenCardToPlayer(const Card &card, const QPointF &deckPos)
{
    auto cardView = std::make_unique<CardView>(card);
    QPointF position = playerInfo->pos + QPointF(cardOffsetX * playerInfo->cardViews.size(), 0);
    cardView->setPos(position);
    cardView->showBack();
    addItem(cardView.get());
    cardView->animateTo(deckPos, position);
    playerInfo->cardViews.push_back(std::move(cardView));

    QRectF sceneRect = itemsBoundingRect();
    setSceneRect(sceneRect);
    view->fitInView(sceneRect, Qt::KeepAspectRatio);

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

void GameScene::showFrontFirstCard()
{
    playerInfo->cardViews[0]->showFront();
}
