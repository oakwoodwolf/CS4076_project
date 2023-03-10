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
    QString resPath{"://res/pics/"};
    explicit recipe(QObject *parent = nullptr);
    recipe(QString name, QString recipeImg, QString recipeText, int difficulty){
         Name = name; RecipeText = recipeText, Difficulty = difficulty;
         RecipeImg = resPath + recipeImg;
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
    QString getImage(){
        return RecipeImg;
    }

private:
    QString Name = "cake";
    QString RecipeText = "";
    QString RecipeImg = "";
    int Difficulty = 1;
    QUrl sourceURL = QUrl("https://www.bbcgoodfood.com/recipes/strawberry-cheesecake-4-easy-steps");

signals:

};

#endif // RECIPE_H
