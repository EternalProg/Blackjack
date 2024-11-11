#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QGraphicsItemAnimation>
#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <card.h>

class CardView : public QGraphicsPixmapItem
{
public:
    CardView(const Card &card, QGraphicsItem *parent = nullptr);

    void showFront();
    void showBack();

    void animateTo(const QPointF &startPos, const QPointF &endPos);
    const Card &getCard() const;

private:
    const Card &card;    // Зберігаємо посилання на модель карти
    QPixmap frontPixmap; // Текстура для передньої сторони
    QPixmap backPixmap;  // Текстура для задньої сторони
    QGraphicsItemAnimation *animation;
    QTimeLine *timeLine;
};

#endif // CARDVIEW_H
