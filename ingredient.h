#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <QString>

class Ingredient
{
public:
    Ingredient(QString name, float capacity) : name(name), capacity(capacity) {}
private:
    QString name;
    float capacity;

};

#endif // INGREDIENT_H
