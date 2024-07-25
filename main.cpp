#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "salesPrediction.h"
#include "salesInputOutput.h"


using namespace std;


// For error testing, the test data for April has a typo in the file name (missing first letter)

int main() {
    //TODO: Get rid of test function-calls and add in CLI menu

    //Brian's Temporary Test Function Calls
    Sale currentSearchSale;
    currentSearchSale.outputSale();

    //Chuck's Temporary Test Function Calls
    SalesPrediction currentSales;
    try {
        currentSales.salesPrediction();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;

}
