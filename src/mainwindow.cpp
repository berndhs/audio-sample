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
MainWindow::init()
{
    m_player_in = new QMediaPlayer;
    connect(m_player_in, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    m_player_out = new QMediaPlayer;
\
    QString dir = QDir::currentPath();
    m_player_in->setMedia(QUrl::fromLocalFile(dir + "/Learning to Fly - Pink Floyd [144p].3gp"));
    m_player_in->setVolume(99);

    m_player_in->play();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::positionChanged(qint64 newpos)
{
    qDebug() << Q_FUNC_INFO << "new pos " << newpos;
}
