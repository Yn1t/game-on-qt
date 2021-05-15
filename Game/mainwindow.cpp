#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->killed = 0;

    this->setWindowState(Qt::WindowFullScreen);

    button_parent = new QGraphicsRectItem;
    btn_exit = new Button(QPixmap(":/Menu/return.png"), button_parent);
    btn_exit->setGeometry(width() / 2 - 60, height() - 100, 180, 60);
    btn_exit->setPos(0, 0);

    graphicsView = new QGraphicsView(this);

    bridge = new scene_node();
    bridge->scene = new Bridge();
    forest = new scene_node();
    forest->scene = new Forest();
    lava_room = new scene_node();
    lava_room->scene = new Lava_room();
    dungeon_top = new scene_node();
    dungeon_top->scene = new Dungeon_top();

    bridge->right = forest;
    bridge->left = lava_room;

    lava_room->right = bridge;

    forest->left = bridge;
    forest->up = dungeon_top;
    forest->down = forest;
    forest->right = forest;

    dungeon_top->down = forest;

    current_scene = bridge;
    current_scene->scene->addItem(button_parent);
    button_parent->setPos(1000, 900);

    graphicsView->setScene(current_scene->scene);
    graphicsView->setGeometry(this->geometry());
    graphicsView->setSceneRect(this->rect());

    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    current_scene->scene->setSceneRect(this->rect());

    hero = new Sprite_hero();
    graphicsView->scene()->addItem(hero);

    hero->setPos(0, 540);

    timer = new QTimer();

    connect(timer, &QTimer::timeout, hero, &Essence::slotGameTimer);
    connect(timer, &QTimer::timeout, this, &MainWindow::change_scene);
    connect(hero, &Essence::end_game, this, &MainWindow::game_lose_slot);
    connect(forest->scene, &custom_scene::scores_inc, this, &MainWindow::killed_inc);
    connect(dungeon_top->scene, &custom_scene::scores_inc, this, &MainWindow::killed_inc);\
    connect(lava_room->scene, &custom_scene::scores_inc, this, &MainWindow::killed_inc);

    timer->start(1);

    connect(btn_exit, &Button::pressed, this, &MainWindow::exit_game_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
    //timer->stop();
    //delete hero;
    /*bridge->scene->deleteLater();
    delete bridge;
    forest->scene->deleteLater();
    delete forest;
    lava_room->scene->deleteLater();
    delete lava_room;
    dungeon_top->scene->deleteLater();
    delete dungeon_top;
    btn_exit->deleteLater();*/
    delete timer;
    graphicsView->deleteLater();
}

void MainWindow::change_scene()
{
    if (this->hero->x() == 1950)
    {
        set_new_scene(current_scene->right);
        hero->setPos(-199, this->hero->y());
    }
    else if (this->hero->x() == -200)
    {
        set_new_scene(current_scene->left);
        hero->setPos(1949, this->hero->y());
    }
    else if (this->hero->y() == -100)
    {
        set_new_scene(current_scene->up);
        hero->setPos(this->hero->x(), 1095);
    }
    else if (this->hero->y() == 1100)
    {
        set_new_scene(current_scene->down);
        hero->setPos(this->hero->x(), -99);
    }
}

void MainWindow::set_new_scene(scene_node *scene)
{
    current_scene = scene;
    graphicsView->setScene(current_scene->scene);
    graphicsView->scene()->addItem(hero);
    current_scene->scene->addItem(button_parent);
}

void MainWindow::exit_game_slot()
{
    emit exit_game();
}

void MainWindow::game_lose_slot()
{
    emit dwarf_death_signal(this->killed);
}

void MainWindow::killed_inc()
{
    this->killed++;
    if (this->killed == 2)
        emit end_game_win();
}
