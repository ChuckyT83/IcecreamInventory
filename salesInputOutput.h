#include <iostream>

using namespace std;


class Sale
{
    public:
        void inputNewSale();
        void outputSale();
    private:
        void calculateOutputProfits(string date, double chocolate, double vanilla, double strawberry, double wafflecones, double sugarcones);
        string dateSold;
        double amountVanillaSold;
        double amountChocolateSold;
        double amountStrawberrySold;
        double amountWaffleconeSold;
        double amountSugarconeSold;
};


