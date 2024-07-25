#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "salesPrediction.h"


using namespace std;


// For error testing, the test data for April has a typo in the file name (missing first letter)

int main() {

    SalesPrediction currentSales;
    try {
        currentSales.salesPrediction();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;

}
