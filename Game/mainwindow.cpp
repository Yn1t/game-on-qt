#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen);

    graphicsView = new QGraphicsView(this);
    scene = new Bridge();
    graphicsView->setScene(scene);

    graphicsView->setGeometry(this->geometry());
    graphicsView->setSceneRect(this->rect());
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(this->rect());

    hero = new Sprite_hero();

    hero->setPos(200, 200);
    scene->addItem(hero);


    timer = new QTimer();
    connect(timer, &QTimer::timeout, hero, &Sprite_hero::slotGameTimer);
    timer->start(1000/500);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hero;
    delete scene;
}

