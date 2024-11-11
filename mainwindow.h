#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAudioOutput>
#include <QMainWindow>
#include <QMediaPlayer>
#include <game.h>
#include <gamescene.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayResult();

private slots:
    void onHitButtonClicked();
    void onStandButtonClicked();

    void onIncreaseBetButtonClicked();
    void onDecreaseBetButtonClicked();
    void onLeaveTableButtonClicked();
    void onStayButtonClicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Game> game;
    std::unique_ptr<QMediaPlayer> backgroundMusic;
    std::unique_ptr<QAudioOutput> audioOutput;

    void updateStatusBar();
    void enableBetButtons(bool enable);
};
#endif // MAINWINDOW_H
