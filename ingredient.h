#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <QString>

class Ingredient
{
public:
    Ingredient(QString name, float capacity) : name(name), capacity(capacity) {}
    virtual QString getCapacity() = 0; //Subclasses handle this
    virtual QString displayIngredient() = 0;
    QString getName(){
        return name;
    }
protected:
    QString name;
    float capacity;

};

#endif // INGREDIENT_H
