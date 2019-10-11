#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>

const static int mapSize = 5; // 3x3 map, where are 3 towns and 2 roads for each row
const static int playerNumber = 2; // 2 players in game

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto vLayout = new QVBoxLayout(ui->map);
    for (int i = 0; i < mapSize; ++i)
    {
        auto hLayout = new QHBoxLayout;
        vLayout->addLayout(hLayout);

        for (int j = 0; j < mapSize; ++j)
        {
            auto loc = new Location(ui->map);

            if (j & 1)
                loc->setType(Location::Type::Road);

            hLayout->addWidget(loc);

            m_locations.append(loc);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
