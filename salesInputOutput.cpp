#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include "salesInputOutput.h"


using namespace std;

//constants for product prices
const double icecreamValue = 3.50;
const double waffleconeValue = 1.50;
const double sugarconeValue = 1;


//allows user to input a new sale
void Sale::inputNewSale()
{



}

//allows user to output information and calculations about a specific saved date
void Sale::outputSale()
{
    //function-specific variables
    int month;
    string date;
    string monthString;
    bool validInput = false;

    //Asks the user to input a date until a date in the correct format has been entered.
    while (validInput == false)
    {
        cout << "Enter the month, day, and year for the day of sales you would like to search in the format MM/DD/YYYY: " << endl;
        cin >> date;

        if (date.size()>= 8 && date.size()<= 10)
        {
            validInput = true;
        }
        else
        {
            cout << "Please enter a valid date in the proper format." << endl;
        }
    }
    

    //Asks user to input month in number format again.
    //Asks until valid input is confirmed
    validInput = false;
    while (validInput == false)
    {
        cout << "Please enter the digit of the specific month you'd like to search." << endl;
        cin >> month;
        switch (month)
        { 
            case 1:
                monthString = "January";
                validInput = true;
                break;
            case 2:
                monthString = "February";
                validInput = true;
                break;
            case 3:
                monthString = "March";
                validInput = true;
                break;
            case 4:
                monthString = "April";
                validInput = true;
                break;
            case 5:
                monthString = "May";
                validInput = true;
                break;
            case 6:
                monthString = "June";
                validInput = true;
                break;
            case 7:
                monthString = "July";
                validInput = true;
                break;
            case 8:
                monthString = "August";
                validInput = true;
                break;
            case 9:
                monthString = "September";
                validInput = true;
                break;
            case 10:
                monthString = "October";
                validInput = true;
                break;
            case 11:
                monthString = "November";
                validInput = true;
                break;
            case 12:
                monthString = "December";
                validInput = true;
                break;
            default:
                monthString = "Invalid month";
                break;
        };
    }
        
    //open file
    string filename = "./data/" + monthString + "SalesData.txt";
    ifstream dataFile(filename);

    //simple bool who's only purpose is to tell user that they had a successful search
    bool searchSuccess;

    //dummy string to hold header line in data file
    string headerLine;
    getline(dataFile, headerLine, '\n');

    //parses through every line and stops to print data when the correct line is found
    while(dataFile >> dateSold >> amountChocolateSold >> amountVanillaSold >> amountStrawberrySold >> amountWaffleconeSold >> amountSugarconeSold)
    {

        if (dateSold == date)
        {
            cout << "Date of sales found!" << "\n" << "\n";

            double totalDailySales = amountChocolateSold + amountVanillaSold + amountStrawberrySold + amountWaffleconeSold + amountSugarconeSold;

            //decorative header lines
            cout << "\n" << setw(32) << "--Stock Sold--";
            cout << "\n" << setw(10) << "Date " << setw(9) << "Chocolate " << setw(7) << "Vanilla " << setw(9) << "Strawberry " <<  setw(11)<< "WaffleCones " << setw(10) 
            << "SugarCones " << setw(5) << "Total" << "\n" << "\n";


            //informative line
            cout << setw(10) << dateSold << " " << setw(9) << amountChocolateSold << " " << setw(7) << amountVanillaSold << " " << setw(9) << amountStrawberrySold 
            << " " << setw(11)<< amountWaffleconeSold << " " << setw(10) << amountSugarconeSold << setw(5) << totalDailySales << endl;


            //calculates and prints profits
            calculateOutputProfits(dateSold, amountChocolateSold, amountVanillaSold, amountStrawberrySold, amountWaffleconeSold, amountSugarconeSold);


            searchSuccess = true;
        }

        //close file
        dataFile.close();
    }
    
    //lets user know if search was a success or not
    if (searchSuccess == true)
    {
        cout << "Search Success!" << endl;
    }
    else
    {
        cout << "No such date found!" << endl;
    }

}

//function to calculate and output profits
void Sale::calculateOutputProfits(string date, double chocolate, double vanilla, double strawberry, double wafflecones, double sugarcones)
{
    //variables & calculations
    double chocolateProfits = chocolate * icecreamValue;
    double vanillaProfits = vanilla * icecreamValue;
    double strawberryProfits = strawberry * icecreamValue;
    double waffleconeProfits = wafflecones * waffleconeValue;
    double sugarconeProfits = sugarcones * sugarconeValue;
    double totalProfits = chocolateProfits + vanillaProfits + strawberryProfits + waffleconeProfits + sugarconeProfits;
    
    //decorative header lines
    cout<< "\n" << setw(32) << "--Profits--" << endl;
    cout << setw(9) << "Date " << setw(9) << "Chocolate " << setw(7) << "Vanilla " << setw(9) << "Strawberry " <<  setw(11)<< "WaffleCones " << setw(10) 
            << "SugarCones " << setw(5) << "Total" << "\n" << "\n";

    //informative lines
    cout << setw(9) << date << setw(6) << "$" <<chocolateProfits << setw(3) << "$" << vanillaProfits << setw(7) << "$" << strawberryProfits <<  setw(9)<< "$" 
    << waffleconeProfits << setw(9) << "$" << sugarconeProfits << setw(6) << "$" << totalProfits << "\n" << "\n";
}