#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QDebug>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "WidgetMarqueeLabel.h"
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QSpacerItem>
#include <QGroupBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void video();
    ~MainWindow();

public slots:
    void move();


private:
    void createVerticalGroupBox();
    void createGridGroupBox();

    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QVideoWidget* videoWidget;

    QMediaPlayer* player1;
    QMediaPlaylist* playlist1;
    QVideoWidget* videoWidget1;

    WidgetMarqueeLabel *ml;
    int currentSpeed;
    QPropertyAnimation* animation;
    QLabel* label;

    QMovie* movie;

    QGroupBox *verticalGroupBox;
    QGroupBox *gridGroupBox;



};

#endif // MAINWINDOW_H

