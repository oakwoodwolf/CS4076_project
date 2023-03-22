#include "recipeloader.h"
#include "qjsonobject.h"
#include "recipe.h"
#include <fstream>
#include <QString>
#include <QFile>
#include <QList>
#include <QJsonArray>
#include <QJsonDocument>
#include <iostream>
#define inputFile   "://res/json/recipes.json"

recipeLoader::recipeLoader()
{

}
QList<recipe*> recipeLoader::LoadRecipes(){
    QList<recipe*> recipes;
    QFile file(inputFile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return recipes;

        QByteArray jsonData = file.readAll();
        QJsonDocument document = QJsonDocument::fromJson(jsonData);
        if (document.isNull())
            return recipes;

        if (!document.isArray())
            return recipes;

        QJsonArray jsonArray = document.array();
        foreach (const QJsonValue & value, jsonArray) {
            if (!value.isObject())
                continue;

            QJsonObject obj = value.toObject();
            QString name = obj.value("recipeName").toString();
            QString text = obj.value("recipeText").toString();
            QString url = obj.value("recipeImg").toString();
            int difficulty = obj.value("difficulty").toInt();

            recipe newRecipe(name, text, url, difficulty);
            recipes.append(&newRecipe);
        }

    return recipes;
}
