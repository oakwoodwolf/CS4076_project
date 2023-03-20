#ifndef RECIPELOADER_H
#define RECIPELOADER_H

#include <QMainWindow>
#include "recipe.h"

class recipeLoader
{
public:
    recipeLoader();
    std::list<recipe> LoadRecipes();
};

#endif // RECIPELOADER_H
