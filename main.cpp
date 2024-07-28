#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "salesPrediction.h"
#include "salesInputOutput.h"
#include "stockManagement.h"



using namespace std;


// For error testing, the test data for April has a typo in the file name (missing first letter)

int main() {
    //TODO: Get rid of test function-calls and add in CLI menu
    const int exitNum = 9;
    int menuChoice = 0;

    loadStockData(); // This loads the stock data at the start

    while (menuChoice != 9)
    {
        cout << "Welcome to ICIM (Ice Cream Inventory Manager)" << "\n\n" <<
        "What would you like to do?" << "\n" 
        << "1. Input sales data of a specific date" << "\n"
        << "2. Output sales data and profits of a specific date" << "\n"
        << "3. Calculate sales prediction for the future" << "\n"
        << "4. Input current stock" << "\n"
        << "5. Order more stock" << "\n"
        << "6. Unit Converter" << "\n"
        << "7. View current stock" << "\n"
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
         else if (menuChoice == 4)
        {
            inputCurrentStock();  // Call the function to input current stock
        }
        else if (menuChoice == 5)
        {
            orderMoreStock();    // Call the function to order more stock
        }
        else if (menuChoice == 6)
        {
            unitConverter();    // Call the function to convert units
        }
          else if (menuChoice == 7)  // Handle new menu option
        {
            viewCurrentStock(); // Call the function to view current stock
        }
        else if (menuChoice == 9)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Unknown menu choice, please try again." << endl;
        }
    }

    saveStockData();
    
    return 0;
}
