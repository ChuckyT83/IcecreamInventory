#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "salesPrediction.h"


using namespace std;




int main() {

    SalesPrediction currentSales;
    try {
        currentSales.salesPrediction();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;

}
