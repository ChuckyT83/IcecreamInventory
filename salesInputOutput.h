#include <iostream>

using namespace std;

//class that contains methods and basic variables required for inputNewSale() and outputSale()
class Sale
{
    public:
        void inputNewSale();//func to input a new line of save data onto a chosen month's data file
        void outputSale();//reads and does calculations on a line of save data from a chosen month's data file
    private:
        void calculateOutputProfits(string date, double chocolate, double vanilla, double strawberry, double wafflecones, double sugarcones);//calculates profits from data gathered from outputSale()
        string dateSold;//holds date from save file while searching it for inputted date
        double amountVanillaSold;//holds amount of vanilla from save file while searching it for inputted date
        double amountChocolateSold;//holds amount of chocolate from save file while searching it for inputted date
        double amountStrawberrySold;//holds amount of strawberry from save file while searching it for inputted date
        double amountWaffleconeSold;//holds amount of waffle cones from save file while searching it for inputted date
        double amountSugarconeSold;//holds amount of sugar cones from save file while searching it for inputted date
};


