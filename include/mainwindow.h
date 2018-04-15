#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void init ();
    ~MainWindow();


public slots:
    void positionChanged (qint64 newpos);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player_in;
    QMediaPlayer *m_player_out;
};

#endif // MAINWINDOW_H
