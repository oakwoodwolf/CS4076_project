#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"
#include "tbspingredient.h"
#include <QUrl>
#include <QObject>
#include <QString>
using std::string;

class recipe : public QObject
{
    Q_OBJECT
protected:
    QString Name = "cake";
public:
    QString resPath{"://res/pics/"};
    explicit recipe(QObject *parent = nullptr);
    recipe(QString name, QString recipeImg, QString recipeText, int difficulty){
         Name = name; RecipeText = recipeText, Difficulty = difficulty;
         RecipeImg = resPath + recipeImg;
    }
    recipe(QString name, QString recipeImg, QString recipeText, int difficulty, QUrl link){
         Name = name; RecipeText = recipeText, Difficulty = difficulty, sourceURL = link;
         RecipeImg = resPath + recipeImg;
    }
    ~recipe(){
        delete[] ingredients;
    }
    QString getName() const{
        return Name;
    }
    virtual QString getRecipeText(){
        QString output;
        output = /*printIngredients() +*/ RecipeText;
        return output;
    }
    int getDifficulty(){
        return Difficulty;
    }
    QUrl getURL(){
        return sourceURL;
    }
    QString getImage(){
        return RecipeImg;
    }
    void setIngredient(int index, tbspIngredient* ing){
        ingredients[index] = ing;
        ingredientSize++;
    }
    QString printIngredients() const {
        QString output = "Ingredients: \n";
        if (ingredients != NULL){
            for (int i = 0; i < sizeof(ingredients); i++){
                output = output + (ingredients[i]->displayIngredient());
            }
        }

        return output;
    }

private:

    QString RecipeText = "";
    Ingredient** ingredients;
    QString RecipeImg = "";
    int Difficulty = 1;
    int ingredientSize = 0;
    QUrl sourceURL = QUrl("https://www.bbcgoodfood.com/recipes/strawberry-cheesecake-4-easy-steps");
    friend class recipeLoader;
signals:

};

#endif // RECIPE_H
