#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(new Game(this))
    , backgroundMusic(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))

{
    ui->setupUi(this);
    game->setDeckPos(ui->deckLabel->pos());

    connect(ui->hitButton, &QPushButton::clicked, this, &MainWindow::onHitButtonClicked);
    connect(ui->standButton, &QPushButton::clicked, this, &MainWindow::onStandButtonClicked);
    connect(ui->increaseBetButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onIncreaseBetButtonClicked);
    connect(ui->decreaseBetButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onDecreaseBetButtonClicked);
    connect(ui->leaveTableButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onLeaveTableButtonClicked);
    connect(ui->stayTableButton, &QPushButton::clicked, this, &MainWindow::onStayButtonClicked);
    connect(game.get(), &Game::resultReady, this, &MainWindow::displayResult);

    backgroundMusic->setSource(QUrl("qrc:/sounds/backgroundChillBeats.mp3"));
    backgroundMusic->setAudioOutput(audioOutput.get());
    audioOutput->setVolume(0.3);

    backgroundMusic->setLoops(QMediaPlayer::Infinite);
    backgroundMusic->play();

    ui->playerGraphicsView->setScene(game->getHumanScene());
    ui->dealerGraphicsView->setScene(game->getDealerScene());

    enableBetButtons(false);

    game->startNewGame();
    updateStatusBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHitButtonClicked()
{
    game->humanRound();
    updateStatusBar();
}

void MainWindow::onStandButtonClicked()
{
    game->dealerRound();
    updateStatusBar();
}

void MainWindow::onIncreaseBetButtonClicked()
{
    game->getHuman()->increaseBet(10);
    updateStatusBar();
}

void MainWindow::onDecreaseBetButtonClicked()
{
    game->getHuman()->decreaseBet(10);
    updateStatusBar();
}

void MainWindow::onLeaveTableButtonClicked()
{
    close();
}

void MainWindow::onStayButtonClicked()
{
    game->startNewGame();
    updateStatusBar();
    enableBetButtons(false);
    ui->resultLabel->setText("");
}

void MainWindow::enableBetButtons(bool enable)
{
    ui->increaseBetButton->setEnabled(enable);
    ui->decreaseBetButton->setEnabled(enable);
    ui->stayTableButton->setEnabled(enable);
}

void MainWindow::updateStatusBar()
{
    ui->statusBar->showMessage(QString("Balance: $%1 | Bet: $%2")
                                   .arg(game->getHuman()->getBalance())
                                   .arg(game->getHuman()->getBet()));

    ui->humanScore->setText(QString("%1").arg(game->getHuman()->getScore()));
    size_t dealerScore = game->getDealer()->getScore();
    if (game->getDealer()->hasHiddenCard()) {
        dealerScore -= game->getDealer()->getHiddenCardScore();
    }
    ui->dealerScore->setText(QString("%1").arg(dealerScore));
}
void MainWindow::displayResult()
{
    int humanScore = game->getHuman()->getScore();
    int dealerScore = game->getDealer()->getScore();
    int bet = game->getHuman()->getBet();

    if (humanScore > 21) {
        ui->resultLabel->setText("You busted. You lose!");
        game->getHuman()->updateBalance(-bet);
    } else if (dealerScore > 21) {
        ui->resultLabel->setText("Dealer busted. You win!");
        game->getHuman()->updateBalance(bet);
    } else if (humanScore > dealerScore) {
        ui->resultLabel->setText("You win!");
        game->getHuman()->updateBalance(bet);
    } else if (dealerScore > humanScore) {
        ui->resultLabel->setText("Dealer wins. You lost.");
        game->getHuman()->updateBalance(-bet);
    } else {
        ui->resultLabel->setText("It's a draw.");
    }

    game->getHuman()->resetBet();
    enableBetButtons(true);
    updateStatusBar();
}
