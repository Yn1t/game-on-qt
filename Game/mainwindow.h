#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <QShortcut>
#include <QObject>

#include "custom_scene.h"
#include "object.h"
#include "sprite_hero.h"
#include "bridge.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    custom_scene *scene;
    QGraphicsView *graphicsView;
    Object *hero;
    QTimer *timer;
};
#endif // MAINWINDOW_H
