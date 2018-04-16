#include <QDebug>
#include <QDir>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void
MainWindow::init(QApplication & app)
{
    m_app = &app;
    m_player_in = new QMediaPlayer;
    connect(m_player_in, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(ui->playrate,SIGNAL(valueChanged(int)),this,SLOT(playPercentChanged(int)));
    connect (ui->quitbutton,SIGNAL(clicked()),this,SLOT(quit()));
    m_player_out = new QMediaPlayer;
\
    QString dir = QDir::currentPath();
    m_player_in->setMedia(QUrl::fromLocalFile(dir + "/Learning to Fly - Pink Floyd [144p].3gp"));
    m_player_in->setVolume(99);
    m_player_in->setPlaybackRate(1.5);
    m_player_in->play();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::positionChanged(qint64 newpos)
{
    qDebug() << Q_FUNC_INFO << "new pos " << newpos;
}

void MainWindow::playPercentChanged(int newPercent)
{
    qDebug() << Q_FUNC_INFO << "new percent " << newPercent;
    int min = ui->playrate->minimum();
    int max = ui->playrate->maximum();
    double newval = newPercent/(max-min);
    playRateChanged(newval);
}

void
MainWindow::playRateChanged(float newRate)
{
    qDebug() << Q_FUNC_INFO << "NEW RATE " << newRate;
    m_player_in->setPlaybackRate(newRate);
}

void
MainWindow::quit()
{
  m_app->quit();
}
