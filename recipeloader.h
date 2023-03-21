#ifndef RECIPELOADER_H
#define RECIPELOADER_H

#include <QMainWindow>
#include "recipe.h"

class recipeLoader
{
public:
    recipeLoader();
    QList<recipe> LoadRecipes();
};

#endif // RECIPELOADER_H
