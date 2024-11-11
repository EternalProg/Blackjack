#include "deck.h"

#include <QSettings>
#include <algorithm>
#include <iostream>
#include <random>

Deck::Deck() {
    for (int r = static_cast<int>(Card::Rank::Ace); r <= static_cast<int>(Card::Rank::King); ++r) {
        for (int s = static_cast<int>(Card::Suit::Clubs); s <= static_cast<int>(Card::Suit::Hearts);
             ++s) {
            cards.emplace_back(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s));
        }
    }
    loadDeckSkin(getLastDeckID());
    //shuffle();
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);
    i = 0;
    // https://en.cppreference.com/w/cpp/algorithm/random_shuffle
}

Card Deck::draw() noexcept
{
    return cards[i++];
}

bool Deck::isEmpty() const noexcept
{
    return i >= cards.size();
}

Deck::~Deck()
{
    saveLastDeckID(getLastDeckID());
}

void Deck::loadDeckSkin(uint8_t deckID)
{
    auto backPath = QString(":/deckSkins/cardsImages/deck%1/back.png").arg(deckID);
    int index = 0;
    for (int r = 1; r < 14; ++r) {
        for (int s = 1; s < 5; ++s) {
            auto frontPath
                = QString(":/deckSkins/cardsImages/deck%1/%2_%3.png").arg(deckID).arg(r).arg(s);
            cards[i++].setSkin(frontPath, backPath);
            std::cout << "Skin for " << i << "th card is loaded" << std::endl;
        }
    }
}

void DeckSkinLoader::saveLastDeckID(uint8_t deckID)
{
    QSettings settings("Blackjack", "config");
    settings.setValue("LastDeckID", deckID);
}

uint8_t DeckSkinLoader::getLastDeckID()
{
    QSettings settings("Blackjack", "config");
    return settings.value("LastDeckID", 1).toUInt();
    // Якщо немає збереженого значення, повертає 1
}
