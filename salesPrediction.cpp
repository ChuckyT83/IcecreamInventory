#include "salesPrediction.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void SalesPrediction::salesPrediction(){
    parseSalesData();
    printSalesData();
    salesAnalysis();
    printSalesAnalysis();
    predictSales();
}

void SalesPrediction::parseSalesData() {

    string input;
    cout << "Enter the month for the sales data: ";
    cin >> input;

    string filename = input + "salesData.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Couldn't read file: " << filename << "\n";
    }
    
    //Populate the salesDataHeader array
    for(typeCount = 0; typeCount < 6; typeCount++) {
        inputFile >> salesDataHeader[typeCount];
    }
    //Populate the salesDataDate array and the salesData array
    for(dateCount = 0; dateCount < 31; dateCount++) {
        for(typeCount = 0; typeCount < 6; typeCount++) {
            if (typeCount == 0) {
                inputFile >> salesDataDate[dateCount];
            }
            else{
                inputFile >> salesData[typeCount - 1][dateCount];
            }
        }
    }

    inputFile.close();
}

string SalesPrediction::setMonth() {
    //Get the month number from the first character of the first date in the salesDataDate array
    int monthNum = stoi(salesDataDate[0].substr(0, 1));
    string month;
    //Set the month name based on the month number
    switch (monthNum)
    { 
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        case 12:
            month = "December";
            break;
        default:
            month = "Invalid month";
            break;
    }
    setNumDays(monthNum);
    return month;
}

void SalesPrediction::setNumDays(int month) {
    //Set the number of days in the month based on the month number
    int year = stoi(salesDataDate[0].substr(4, 4));
    switch (month)
    {
        case 1:
            numDays = 31;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                numDays = 29;
            }
            else
            numDays = 28;
            break;
        case 3:
            numDays = 31;
            break;
        case 4:
            numDays = 30;
            break;
        case 5:
            numDays = 31;
            break;
        case 6:
            numDays = 30;
            break;
        case 7:
            numDays = 31;
            break;
        case 8:
            numDays = 31;
            break;
        case 9:
            numDays = 30;
            break;
        case 10:
            numDays = 31;
            break;
        case 11:
            numDays = 30;
            break;
        case 12:
            numDays = 31;
            break;
        default:
            numDays = 0;
            break;
    }
}

void SalesPrediction::printSalesData() {
    //Set the current month
    currentMonth = setMonth();

    //print the salesDataHeader array
    for (typeCount = 0; typeCount < 6; typeCount++) {
        cout << setw(12) << salesDataHeader[typeCount];
    }
    cout << endl;

    //print the salesDataDate array and the salesData array
    for (int dateCount = 0; dateCount < numDays; dateCount++) {
        for (int typeCount = 0; typeCount < 6; typeCount++) {
            if (typeCount == 0) {
                cout << setw(12) << salesDataDate[dateCount];
            }
            else {
                cout << setw(12) << salesData[typeCount - 1][dateCount];
            }
        }
        cout << endl;
    }
}

void SalesPrediction::salesAnalysis() {
    //Calculate the total sales
    for (int dateCount = 0; dateCount < numDays; dateCount++) {
        for (int typeCount = 0; typeCount < 5; typeCount++) {
            totalSales += salesData[typeCount][dateCount];
            totalSalesType[typeCount] += salesData[typeCount][dateCount];
            
        }
        
    }

    //Calculate the average sales
    averageSales = totalSales / numDays;

    //Calculate the average sales for each item
    for (int typeCount = 0; typeCount < 5; typeCount++) {
        averageSalesType[typeCount] = totalSalesType[typeCount] / numDays;
    }

    //Set the initial lowest sales for each item and total sales
    for (int typeCount = 0; typeCount < 5; typeCount++) {
        lowestSalesType[typeCount] = salesData[typeCount][0];
        lowestSales += salesData[typeCount][0];
    }

    //Calculate the highest and lowest sales
    for (int dateCount = 0; dateCount < numDays; dateCount++) {
        tempSales = 0;
        for (int typeCount = 0; typeCount < 5; typeCount++) {

        //Set highest daily sales for each item
        if (salesData[typeCount][dateCount] > highestSalesType[typeCount]) {
            highestSalesType[typeCount] = salesData[typeCount][dateCount];
            highestSalesTypeDay[typeCount] = dateCount;
        }

        //Set lowest daily sales for each item
        if (salesData[typeCount][dateCount] < lowestSalesType[typeCount]) {
            lowestSalesType[typeCount] = salesData[typeCount][dateCount];
            lowestSalesTypeDay[typeCount] = dateCount;
        }

        //Calculate the total sales for each day
        tempSales += salesData[typeCount][dateCount];
        }

        //Set highest and lowest daily total sales
        if (tempSales > highestSales) {
            highestSales = tempSales;
            highestSalesDay = dateCount;
        }
        if (tempSales < lowestSales) {
            lowestSales = tempSales;
            lowestSalesDay = dateCount;
        }
    }

    predictSales();
}
void SalesPrediction::printSalesAnalysis() {
    
    
    
    //Print results
    cout << endl << "Sales Analysis for " << currentMonth << endl << "-----------------------" << endl;
    cout << endl << "Total Sales for " << currentMonth << ": " << totalSales << endl;
    cout << "Average Daily Sales for " << currentMonth << ": " << averageSales << endl;
    cout << "Highest Daily Sales for " << currentMonth << ": " << highestSales << " on " << salesDataDate[highestSalesDay] << endl;
    cout << "Lowest Daily Sales for " << currentMonth << ": " << lowestSales << " on " << salesDataDate[lowestSalesDay] << endl << endl;
    
    cout << "Sales Analysis by Type - Ice Cream is per gallon/Cones is per case" << endl << "-----------------------" << endl;
    for (int typeCount = 0; typeCount < 5; typeCount++) {
        cout << "Average Sales for " << salesDataHeader[typeCount + 1] << ": " << averageSalesType[typeCount] << endl;
        cout << "Highest Sales for " << salesDataHeader[typeCount + 1] << ": " << highestSalesType[typeCount] << " on " << salesDataDate[highestSalesTypeDay[typeCount]] << endl;
        cout << "Lowest Sales for " << salesDataHeader[typeCount + 1] << ": " << lowestSalesType[typeCount] << " on " << salesDataDate[lowestSalesTypeDay[typeCount]] << endl;
        cout << "Total Sales for " << salesDataHeader[typeCount + 1] << ": " << totalSalesType[typeCount] << endl;
        cout << "Predicted Sales for " << salesDataHeader[typeCount + 1] << " next month: " << predictedSales[typeCount] << endl << endl;
    }
}

void SalesPrediction::predictSales() {
    int monthNum = stoi(salesDataDate[0].substr(0, 1));
    float predModifier = 1;  //Modifier for the predicted sales based on the month

    //Current logic is to increase sales for the next month by 10% in March, 20% in April and May, 30% in June, and decrease by 10% in August and September
    //Other months keep the modifier at 1
    switch (monthNum)
    {
        case 3:
            predModifier = 1.1;
            break;
        case 4:
            predModifier = 1.2;
            break;
        case 5:
            predModifier = 1.2;
            break;
        case 6:
            predModifier = 1.3;
            break;
        case 8:
            predModifier = .9;
            break;
        case 9:
            predModifier = .9;
            break;
        default:
            predModifier = 1;
            break;   
    }
    //TODO - Add logic to compare sales for the current month to the previous month and adjust the modifier accordingly

    //Calculate the predicted sales for the next month
    for (int typeCount = 0; typeCount < 5; typeCount++) {
        predictedSales[typeCount] = totalSalesType[typeCount] * predModifier;
    }
}

