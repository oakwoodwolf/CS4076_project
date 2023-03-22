#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "recipeloader.h"
#include <QUrl>
#include <QDesktopServices> // for opening a link
#include <QPixmap>
QList<recipe*> recipes;
recipeLoader loader;
std::list<int>::iterator it;
recipe recipe0 = recipe("Strawberry CheeseCake", "strawberry-cheesecake-11.jpg","To make the base, butter and line a 23cm loose-bottomed tin with baking parchment. Put the digestive biscuits in a plastic food bag and crush to crumbs using a rolling pin. Transfer the crumbs to a bowl, then pour over the melted butter. Mix thoroughly until the crumbs are completely coated. Tip them into the prepared tin and press firmly down into the base to create an even layer. Chill in the fridge for 1 hr to set firmly.For more detail on how to make a biscuit base, take a look at our how to make a biscuit base video.\nSTEP 2\nSlice the vanilla pod in half lengthways, leaving the tip intact, so that the two halves are still joined. Holding onto the tip of the pod, scrape out the seeds using the back of a kitchen knife.\nSTEP 3\nPour the double cream into a bowl and whisk with an electric mixer until it’s just starting to thicken to soft peaks. Place the soft cheese, icing sugar and the vanilla seeds in a separate bowl, then beat for 2 mins with an electric mixer until smooth and starting to thicken, it will get thin and then start to thicken again. Tip in the double cream and fold it into the soft cheese mix. You’re looking for it to be thickened enough to hold its shape when you tip a spoon of it upside down. If it’s not thick enough, continue to whisk. Spoon onto the biscuit base, starting from the edges and working inwards, making sure that there are no air bubbles. Smooth the top of the cheesecake down with the back of a dessert spoon or spatula. Leave to set in the fridge overnight.\nSTEP 4\nBring the cheesecake to room temperature about 30 mins before serving. To remove it from the tin, place the base on top of a can, then gradually pull the sides of the tin down. Slip the cake onto a serving plate, removing the lining paper and base. Purée half the strawberries in a blender or food processor with the icing sugar and 1 tsp water, then sieve. Pile the remaining strawberries onto the cake, and pour the purée over the top.",1);
recipe recipe1 = recipe("Peppermint Creams", "peppermint-creams-d7716e6.jpg","To make the base, butter and line a 23cm loose-bottomed tin with baking parchment. Put the digestive biscuits in a plastic food bag and crush to crumbs using a rolling pin. Transfer the crumbs to a bowl, then pour over the melted butter. Mix thoroughly until the crumbs are completely coated. Tip them into the prepared tin and press firmly down into the base to create an even layer. Chill in the fridge for 1 hr to set firmly.For more detail on how to make a biscuit base, take a look at our how to make a biscuit base video.\nSTEP 2\nSlice the vanilla pod in half lengthways, leaving the tip intact, so that the two halves are still joined. Holding onto the tip of the pod, scrape out the seeds using the back of a kitchen knife.\nSTEP 3\nPour the double cream into a bowl and whisk with an electric mixer until it’s just starting to thicken to soft peaks. Place the soft cheese, icing sugar and the vanilla seeds in a separate bowl, then beat for 2 mins with an electric mixer until smooth and starting to thicken, it will get thin and then start to thicken again. Tip in the double cream and fold it into the soft cheese mix. You’re looking for it to be thickened enough to hold its shape when you tip a spoon of it upside down. If it’s not thick enough, continue to whisk. Spoon onto the biscuit base, starting from the edges and working inwards, making sure that there are no air bubbles. Smooth the top of the cheesecake down with the back of a dessert spoon or spatula. Leave to set in the fridge overnight.\nSTEP 4\nBring the cheesecake to room temperature about 30 mins before serving. To remove it from the tin, place the base on top of a can, then gradually pull the sides of the tin down. Slip the cake onto a serving plate, removing the lining paper and base. Purée half the strawberries in a blender or food processor with the icing sugar and 1 tsp water, then sieve. Pile the remaining strawberries onto the cake, and pour the purée over the top.",1);
recipe * recipePtr = &recipe1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    recipes = loader.LoadRecipes();
    recipePtr = recipes.first();
    QPixmap recipePic (recipePtr->getImage());
    ui->setupUi(this);
    ui->recipeImage->setPixmap(recipePic);
    ui->recipeName->setText(recipePtr->getName());
    ui->textBrowser->setText(recipePtr->getRecipeText());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     QDesktopServices::openUrl(recipePtr->getURL());
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
 switch (index){
    case 1:
     recipePtr = &recipe1;
     break;
    default:
        recipePtr = &recipe0;
     break;
 }
    QPixmap recipePic (recipePtr->getImage());
    ui->recipeImage->setPixmap(recipePic);
    ui->recipeName->setText(recipePtr->getName());
    ui->textBrowser->setText(recipePtr->getRecipeText());

}

