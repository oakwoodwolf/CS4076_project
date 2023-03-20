#include "recipeloader.h"
#include "recipe.h"
#include <fstream>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <iostream>

recipeLoader::recipeLoader()
{

}
std::list<recipe> recipeLoader::LoadRecipes(){

    QFile inputFile("://res/json/recipes.json");

    QByteArray jsonData = inputFile.open();

    std::list<recipe> recipes;
    for (auto& recipeData : jsonData["recipes"]){ //iterate regardless of type
        QString recipeName = QString::fromStdString( recipeData["recipeName"]);
        QString recipeText = QString::fromStdString( recipeData["recipeText"]);
        QString recipeImg = QString::fromStdString( recipeData["recipeImg"]);
        QString recipeUrl = QString::fromStdString( recipeData["recipeUrl"]);
        int difficulty = recipeData["difficulty"];
        recipe recipe(recipeName, recipeImg, recipeText, difficulty);
        recipes.push_back(recipe);
    }
    return recipes;
}
