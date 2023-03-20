#include "recipeloader.h"
#include "qjsonobject.h"
#include "recipe.h"
#include <fstream>
#include <QString>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <iostream>
#define inputFile   "://res/json/recipes.json"

recipeLoader::recipeLoader()
{

}
std::list<recipe> recipeLoader::LoadRecipes(){

    QFile file;
    QString contents;
    //Read file
    file.setFileName(QString::fromStdString(inputFile));
    file.open(QIODevice::ReadOnly);
    contents = file.readAll();
    file.close();
    qWarning() << contents;
    QJsonDocument recipeDoc = QJsonDocument::fromJson(contents.toUtf8());
    QJsonValue val = recipeDoc.object();
    QJsonArray recipeArray = val.toArray();



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
