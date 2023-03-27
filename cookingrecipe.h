#ifndef COOKINGRECIPE_H
#define COOKINGRECIPE_H

#include "recipe.h"
#include <QString>

class cookingRecipe : public recipe
{
public:
    explicit cookingRecipe(QObject *parent = nullptr);
    QString getRecipeText(){
        QString toReturn = "";
        return toReturn;
    }
};

#endif // COOKINGRECIPE_H
