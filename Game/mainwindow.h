#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <QShortcut>
#include <QObject>
#include <QList>

#include "custom_scene.h"
#include "object.h"
#include "sprite_hero.h"
#include "bridge.h"
#include "forest.h"
#include "lava_room.h"
#include "dungeon_top.h"
#include "button.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    int killed;
    struct scene_node{
        custom_scene* scene;
        scene_node* up = nullptr;
        scene_node* down = nullptr;
        scene_node* left = nullptr;
        scene_node* right = nullptr;
    };


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_new_scene(scene_node* scene);

private:
    Ui::MainWindow *ui;
    scene_node* current_scene;
    scene_node* bridge;
    scene_node* forest;
    scene_node* lava_room;
    scene_node* dungeon_top;
    Essence *hero;
    QGraphicsView *graphicsView;
    QTimer *timer;
    Button *btn_exit;
    QGraphicsItem* button_parent;

public slots:
    void change_scene();
    void game_lose_slot();
    void exit_game_slot();
    void killed_inc();
    //void game_win_slot();

signals:
    void dwarf_death_signal(int scores);
    void exit_game();
    void end_game_win();
};
#endif // MAINWINDOW_H
