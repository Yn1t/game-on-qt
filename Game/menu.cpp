#include "menu.h"

Menu::Menu(QWidget* parent) : QWidget(parent)
{
    background = new QPixmap(":/Menu/main.png");
    about = new QPixmap(":/Menu/Info.png");
    death_img = new QPixmap(":/Menu/death.png");
    win_img = new QPixmap(":/Menu/win.png");

    this->setWindowState(Qt::WindowFullScreen);

    drawMenu();

    this->setWindowTitle("RPG");
}

Menu::~Menu()
{
    delete main_window;
}

void Menu::About()
{
    delete btn_about;
    delete btn_exit;
    delete btn_start;
    delete btn_info;
    delete layout;

    drawAbout();
}

void Menu::Game()
{
    delete btn_about;
    delete btn_exit;
    delete btn_start;
    delete btn_info;
    delete layout;

    startGame();
}

void Menu::MenuFromGame()
{
    delete game;

    drawMenu();
}

void Menu::_Menu()
{
    delete btn_exit;
    delete layout;
    delete win_res;

    drawMenu();
}

void Menu::drawMenu()
{
    QPixmap bk = background->scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bk);
    this->setPalette(palette);

    layout = new QVBoxLayout(this);

    btn_start = new QPushButton("START");
    btn_about = new QPushButton("HELP");
    btn_info = new QPushButton("INFO");
    btn_exit = new QPushButton("QUIT");

    setStyle(btn_about);
    setStyle(btn_start);
    setStyle(btn_info);
    setStyle(btn_exit);

    layout->addWidget(btn_start);
    layout->addWidget(btn_about);
    layout->addWidget(btn_info);
    layout->addWidget(btn_exit);

    layout->setAlignment(Qt::AlignCenter);

    connect(btn_start, &QPushButton::pressed, this, &Menu::Game);
    connect(btn_about, &QPushButton::pressed, this, &Menu::About);
    connect(btn_info, &QPushButton::pressed, this, &Menu::info);
    connect(btn_exit, &QPushButton::pressed, qApp, &QApplication::quit);
}

void Menu::drawAbout()
{
    win_res = new QLabel();
    QPixmap bk = about->scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bk);
    this->setPalette(palette);

    layout = new QVBoxLayout(this);
    QHBoxLayout hlay;

    btn_exit = new QPushButton("return");
    btn_exit->setGeometry(width() / 2 - 60, height() - 100, 180, 60);
    setStyle(btn_exit);

    layout->addLayout(&hlay);
    hlay.addWidget(btn_exit);
    layout->addWidget(btn_exit);
    layout->setAlignment(Qt::AlignBottom);
    hlay.setAlignment(Qt::AlignCenter);

    connect(btn_exit, &QPushButton::pressed, this, &Menu::_Menu);
}

void Menu::startGame()
{
    game = new MainWindow(this);

    game->grabKeyboard();
    game->show();

    connect(game, &MainWindow::end_game_win, this, &Menu::win);
    connect(game, &MainWindow::dwarf_death_signal, this, &Menu::death);
    connect(game, &MainWindow::exit_game, this, &Menu::MenuFromGame);
}

void Menu::win()
{
    delete game;

    QPixmap bk = win_img->scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bk);
    this->setPalette(palette);

    QString text = "Slimes: 2";
    win_res = new QLabel(text);
    win_res->setStyleSheet("QLabel { background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(200, 110, 100, 200), stop:1 rgba(130, 148, 130, 200)); color : rgba(245,17,12,255); font-size: 45px;}");
    win_res->setGeometry(this->width()/ 2 - 60, this->height() - 400, 180, 60);

    layout = new QVBoxLayout(this);
    QHBoxLayout hlay;

    btn_exit = new QPushButton("return");
    btn_exit->setGeometry(this->width() / 2 - 60, this->height() - 100, 180, 60);
    setStyle(btn_exit);

    hlay.addWidget(btn_exit);
    layout->addLayout(&hlay);

    layout->setAlignment(Qt::AlignBottom);
    hlay.setAlignment(Qt::AlignCenter);

    hlay.addWidget(win_res);

   connect(btn_exit, &QPushButton::pressed, this, &Menu::_Menu);

     connect(btn_exit, &QPushButton::pressed, this, &Menu::_Menu);
}

void Menu::death(int score)
{
    delete game;

    QPixmap bk = death_img->scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bk);
    this->setPalette(palette);

    QString text = "Slimes: " + QString::number(score);
    win_res = new QLabel(text);
    win_res->setStyleSheet("QLabel { background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(200, 110, 100, 200), stop:1 rgba(130, 148, 130, 200)); color : rgba(245,17,12,255); font-size: 45px;}");
    win_res->setGeometry(this->width()/ 2 - 60, this->height() - 400, 280, 60);


    layout = new QVBoxLayout(this);
    QHBoxLayout hlay;

    btn_exit = new QPushButton("return");
    btn_exit->setGeometry(this->width() / 2 - 60, this->height() - 100, 180, 60);
    setStyle(btn_exit);

    hlay.addWidget(btn_exit);
    layout->addLayout(&hlay);

    layout->setAlignment(Qt::AlignBottom);
    hlay.setAlignment(Qt::AlignCenter);

    hlay.addWidget(win_res);

    connect(btn_exit, &QPushButton::pressed, this, &Menu::_Menu);
}

void Menu::setStyle(QPushButton *btn)
{
    btn->setStyleSheet("QPushButton{border: 1px solid transparent;text-align: center;"
            "font-size: 45px;"
            "color:rgba(245,17,12,255);"
            "border-radius: 8px;"
            "border-width: 3px;"
            "border-image: 9,2,5,2; "
            "background-position: top left;"
            "background-origin: content;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(200, 110, 100, 200), stop:1 rgba(130, 148, 130, 200));}"
            "QPushButton::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 rgba(255,200,0,255), stop: 1 rgba(255,0,0,255));}"
            "QPushButton{border-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 200, 200, 200), stop:1 rgba(255, 200, 200, 200));}"
        );
}

void Menu::info()
{
    QMessageBox::information(this, "About", "Petrov Nikita M8O-110B-20", QMessageBox::Ok);
}

