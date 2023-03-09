#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QUrl>
#include <QDesktopServices> // for opening a link
#include <QPixmap>

QUrl currentUrl = QUrl("https://www.bbcgoodfood.com/recipes/strawberry-cheesecake-4-easy-steps", QUrl::TolerantMode);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    QPixmap recipePic ("../res/pics/strawberry-cheesecake-11.jpg");
    ui->setupUi(this);
    ui->recipeImage->setPixmap(recipePic);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     QDesktopServices::openUrl(currentUrl);
}

