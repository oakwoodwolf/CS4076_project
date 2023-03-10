#ifndef RECIPE_H
#define RECIPE_H

#include <QUrl>
#include <QObject>
#include <QString>
using std::string;

class recipe : public QObject
{
    Q_OBJECT
public:
    explicit recipe(QObject *parent = nullptr);
    recipe(QString name, QString recipeText, int difficulty){
         Name = name; RecipeText = recipeText, Difficulty = difficulty;
    }
    QString getName(){
        return Name;
    }
    QString getRecipeText(){
        return RecipeText;
    }
    int getDifficulty(){
        return Difficulty;
    }
    QUrl getURL(){
        return sourceURL;
    }

private:
    QString Name = "cake";
    QString RecipeText = "";
    int Difficulty = 1;
    QUrl sourceURL = QUrl("https://www.bbcgoodfood.com/recipes/strawberry-cheesecake-4-easy-steps");

signals:

};

#endif // RECIPE_H
