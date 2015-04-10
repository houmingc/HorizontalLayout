#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "ticker.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QMovie>
#include <QTimer>
#include <QBoxLayout>
#include <QSpacerItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *window= new QWidget(this);
    window->setWindowTitle("My App");

    ml = new WidgetMarqueeLabel(this);
    ml->setTextFormat(Qt::RichText);
    ml->setAlignment(Qt::AlignBottom);
    ml->setText("this is a very long text because weather is very hot i have sore throat");
    ml->setFont(QFont("Arial", 20,20));

    QGridLayout *layout= new QGridLayout;
    video();


    label= new QLabel;
    movie = new QMovie("/home/ubuntu/Desktop/graphic.gif");
    label->setMovie(movie);
    label->setFixedSize(80,80);
    movie->start();


    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(5000);


    layout->addWidget(videoWidget,0,0);
    layout->addWidget(videoWidget1,0,1);
    layout->addWidget(ml,1,0,1,2);
    layout->addWidget(label,2,0,1,2);
    //layout->addSpacerItem(new QSpacerItem(50,1));



     window->setLayout(layout);
     window->showMaximized();

    //create a scene
    //QGraphicsScene* scene = new QGraphicsScene();
    //create an item to put into the scene
    //QGraphicsRectItem* rect= new QGraphicsRectItem();
    //rect->setRect(0,0,100,100);
    //add the item to the scene
    //scene->addItem(rect);

    //add a view->portion of view is viewable
    //QGraphicsView* view = new QGraphicsView(scene);

    QLabel *gif_anim= new QLabel();
    QMovie *movie= new QMovie(videoWidget);
    gif_anim->setMovie(movie);
    movie->start();


}

//create a new mediaplaylist
//create a mediaplayer
//create a Videowidget
//set playlist

void MainWindow::video()
{
    playlist= new QMediaPlaylist();
    player= new QMediaPlayer;
    videoWidget = new QVideoWidget;
    playlist->addMedia(QUrl::fromLocalFile("/opt/VP.mp4"));
    player->setPlaylist(playlist);


    playlist1= new QMediaPlaylist();
    player1= new QMediaPlayer;
    videoWidget1 = new QVideoWidget;
    playlist1->addMedia(QUrl::fromLocalFile("/opt/hotgirl.mp4"));
    player1->setPlaylist(playlist1);


    player->setVideoOutput(videoWidget);
    player1->setVideoOutput(videoWidget1);
   // videoWidget->show();
    playlist->setCurrentIndex(1);
    playlist1->setCurrentIndex(1);
    player->play();
    player1->play();
}



MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete player1;
}

void MainWindow::move()
{

    animation = new QPropertyAnimation(label,"geometry");
    animation->setDuration(8000);
    animation->setLoopCount(1);
    animation->setStartValue(QRect(0,990,30,30));
    animation->setEndValue(QRect(4000,990,30,30));
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void MainWindow::createVerticalGroupBox()
{
        QVBoxLayout* layout = new QVBoxLayout;

        for (int i=0; i<5; ++i)
            buttons[i]


}




