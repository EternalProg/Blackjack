#ifndef DECK_H
#define DECK_H

#include <QVector>
#include <card.h>

class DeckSkinLoader
{
protected:
    void saveLastDeckID(uint8_t deckID);
    uint8_t getLastDeckID();

public:
    virtual void loadDeckSkin(uint8_t deckID) = 0;
};

class Deck : public DeckSkinLoader
{
public:
    Deck();
    void shuffle();
    Card draw() noexcept;
    bool isEmpty() const noexcept;

    ~Deck();

    // в меню буде нажиматися кнопка з доступнимми скінами і буде передаватися айді колоди сюди через слоти.
    void loadDeckSkin(uint8_t deckID) override;

private:
    QVector<Card> cards;
    size_t i = 0;
};

#endif // DECK_H
