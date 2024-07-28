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
    const int exitNum = 9;
    int menuChoice = 0;

    while (menuChoice != 9)
    {
        cout << "Welcome to ICIM (Ice Cream Inventory Manager)" << "\n\n" <<
        "What would you like to do?" << "\n" 
        << "1. Input sales data of a specific date" << "\n"
        << "2. Output sales data and profits of a specific date" << "\n"
        << "3. Calculate sales prediction for the future" << "\n"
        //TODO: Selma, please add menu selections for your parts of the project here.
        << "9. Exit the program." << "\n";
        cin >> menuChoice;

        if (menuChoice == 1)
        {
            Sale currentNewSale;
            currentNewSale.inputNewSale();
        }
        else if (menuChoice == 2)
        {
            Sale currentSearchSale;
            currentSearchSale.outputSale();
        }
        else if (menuChoice == 3)
        {
            SalesPrediction currentSales;
            try 
            {
                currentSales.salesPrediction();
            }
            catch (const char* msg)
            {
                cerr << msg << endl;
            }
        }
        //TODO: Selma, call your functions here
        else if (menuChoice == 9)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Unknown menu choice, please try again." << endl;
        }
    }
    return 0;
}
