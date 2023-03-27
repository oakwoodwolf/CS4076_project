#ifndef TBSPINGREDIENT_H
#define TBSPINGREDIENT_H

#include "ingredient.h"

class tbspIngredient : public Ingredient
{
public:
    tbspIngredient(QString name, float capacity) : Ingredient(name, capacity){

    }
    QString getCapacity(){
        QString test = QString::number(capacity) + " tbsp ";
        return test;
    }
    QString displayIngredient(){
        QString assemble = getCapacity() + "\t" + getName() + "\n";
        return assemble;
    }
};

#endif // TBSPINGREDIENT_H
