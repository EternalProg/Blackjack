#include "cardview.h"

CardView::CardView(const Card &card, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
    , card(card)
    , frontPixmap(card.getFrontSkin())
    , backPixmap(card.getBackSkin())
    , animation(new QGraphicsItemAnimation)
    , timeLine(new QTimeLine(1000))
{
    setScale(0.35);
    if (card.getIsFront()) {
        setPixmap(frontPixmap);
    } else {
        setPixmap(backPixmap);
    }

    animation->setItem(this);
    animation->setTimeLine(timeLine);
}

void CardView::showFront()
{
    setPixmap(frontPixmap);
}

void CardView::showBack()
{
    setPixmap(backPixmap);
}

void CardView::animateTo(const QPointF &startPos, const QPointF &endPos)
{
    animation->setPosAt(0, startPos);
    animation->setPosAt(1, endPos);

    timeLine->start();
}

const Card &CardView::getCard() const
{
    return card;
}
