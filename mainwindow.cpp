#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recipe.h"
#include "tbspingredient.h"
#include <QUrl>
#include <QList>
#include <QDesktopServices> // for opening a link
#include <QPixmap>
#define recipeCount 6
QList<recipe*> recipeList;
//recipeLoader loader;
recipe recipe0 = recipe("Strawberry CheeseCake", "strawberry-cheesecake-11.jpg","To make the base, butter and line a 23cm loose-bottomed tin with baking parchment. Put the digestive biscuits in a plastic food bag and crush to crumbs using a rolling pin. Transfer the crumbs to a bowl, then pour over the melted butter. Mix thoroughly until the crumbs are completely coated. Tip them into the prepared tin and press firmly down into the base to create an even layer. Chill in the fridge for 1 hr to set firmly.For more detail on how to make a biscuit base, take a look at our how to make a biscuit base video.\nSTEP 2\nSlice the vanilla pod in half lengthways, leaving the tip intact, so that the two halves are still joined. Holding onto the tip of the pod, scrape out the seeds using the back of a kitchen knife.\nSTEP 3\nPour the double cream into a bowl and whisk with an electric mixer until it’s just starting to thicken to soft peaks. Place the soft cheese, icing sugar and the vanilla seeds in a separate bowl, then beat for 2 mins with an electric mixer until smooth and starting to thicken, it will get thin and then start to thicken again. Tip in the double cream and fold it into the soft cheese mix. You’re looking for it to be thickened enough to hold its shape when you tip a spoon of it upside down. If it’s not thick enough, continue to whisk. Spoon onto the biscuit base, starting from the edges and working inwards, making sure that there are no air bubbles. Smooth the top of the cheesecake down with the back of a dessert spoon or spatula. Leave to set in the fridge overnight.\nSTEP 4\nBring the cheesecake to room temperature about 30 mins before serving. To remove it from the tin, place the base on top of a can, then gradually pull the sides of the tin down. Slip the cake onto a serving plate, removing the lining paper and base. Purée half the strawberries in a blender or food processor with the icing sugar and 1 tsp water, then sieve. Pile the remaining strawberries onto the cake, and pour the purée over the top.",1);
recipe recipe1 = recipe("Peppermint Creams", "peppermint-creams-d7716e6.jpg","STEP 1\nSieve the icing sugar into a large bowl. Add a little of the egg white and a few drops of the peppermint essence and mix really well. You want the mixture to come together as a soft dough, so keep adding a little egg white until this starts to happen (you might not need to use all of it). Taste the mixture and add more peppermint essence if desired.\n\nSTEP 2\nDivide the mixture into 20 small balls, then flatten them gently with your fingertips into discs.\n\nSTEP 3\nPlace baking parchment on a large board or tray and space out the discs. Meanwhile, tip the chocolate into a microwavable bowl and heat in 30 second intervals in the microwave until melted, stirring after each blast. Once melted, leave the chocolate to cool for 5-10 mins then carefully dip the peppermint creams in the melted chocolate until they are half coated. Lay them back on the baking parchment to set for 3-4 hours or overnight.",1, QUrl("https://www.bbcgoodfood.com/recipes/peppermint-creams"));
recipe recipe2 = recipe("Chunky Oven Chips", "chips.png","STEP 1\nHeat oven to its highest setting, ideally 250C/fan 230C/gas 9. Cut each potato into 1cm-wide slices, then into 1cm-thick sticks. Blanch in a large pan of boiling water for 3 mins, then drain well.\n\nSTEP 2\nShake the potatoes out onto a roasting pan, drizzle with oil, ensuring each chip is evenly coated, then season well. Bake for about 15-20 mins, turning the potatoes at least twice, until golden brown and crisp.",0, QUrl("https://www.bbcgoodfood.com/recipes/chunky-oven-chips"));
recipe * recipePtr = &recipe0;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    LoadRecipes();
    recipePtr = recipeList.at(0);
    QPixmap recipePic (recipePtr->getImage());
    ui->setupUi(this);
    on_comboBox_started(0);
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
        recipePtr = recipeList.at(index);
    QPixmap recipePic (recipePtr->getImage());
    ui->recipeImage->setPixmap(recipePic);
    ui->recipeName->setText(recipePtr->getName());
    ui->textBrowser->setText(recipePtr->getRecipeText());

}


void MainWindow::on_comboBox_started(int index)
{
    QStringList recipeNames;
    foreach(recipe* const item, recipeList)
    {
        recipeNames.push_back(item->getName()) ;
    }
    //ui->comboBox->clear();
    ui->comboBox->addItems(recipeNames);
}
void MainWindow::LoadRecipes(){
    tbspIngredient test("Test", 3);



    recipeList.append(&recipe0);
    recipeList.append(&recipe1);
    recipeList.append(&recipe2);
}

