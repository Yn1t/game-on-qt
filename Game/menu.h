#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include <QPushButton>
#include <QtGui>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QDebug>

#include "mainwindow.h"
#include "button.h"

class Menu : public QWidget
{
public:
    Menu(QWidget* parent = 0);
    ~Menu();

    void drawMenu();
    void drawAbout();
    void startGame();
    void setStyle(QPushButton* btn);

private:
    MainWindow* main_window;
    QPushButton *btn_start;
    QPushButton *btn_about;
    QPushButton *btn_exit;
    QPushButton *btn_info;
    QPixmap *background;
    QPixmap *about;
    QPixmap *death_img;
    QPixmap *win_img;
    QVBoxLayout* layout;
    MainWindow* game;
    QLabel* win_res;

public slots:
    void About();
    void _Menu();
    void MenuFromGame();
    void Game();
    void death(int scores);
    void win();
    void info();
};

#endif // MENU_H
