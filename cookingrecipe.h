#ifndef COOKINGRECIPE_H
#define COOKINGRECIPE_H

#include "recipe.h"

class cookingRecipe : public recipe
{
public:
    explicit cookingRecipe(QObject *parent = nullptr);
};

#endif // COOKINGRECIPE_H
