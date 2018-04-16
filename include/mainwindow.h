#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void init (QApplication & app);
    ~MainWindow();


public slots:

    void quit();
    void positionChanged (qint64 newpos);

    void playPercentChanged (int newPercent);
    void playRateChanged (float newRate);

private:
    QApplication *m_app;
    Ui::MainWindow *ui;
    QMediaPlayer *m_player_in;
    QMediaPlayer *m_player_out;
};

#endif // MAINWINDOW_H
