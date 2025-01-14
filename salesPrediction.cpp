#include "salesPrediction.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void SalesPrediction::salesPrediction(){
    parseSalesData(setMonth()); //Parse the sales data for the month
    printSalesData(); //Print the sales data
    salesAnalysis(); //Analyze the sales data
    printSalesAnalysis(); //Print the sales analysis
    outputSalesData(); //Output the sales data to a file
}

void SalesPrediction::parseSalesData(string month) {
//This function takes the month as an argument and parses the sales data from the file for that month, storing it in the salesDataHeader, salesDataDate, and salesData arrays

    string filename = "./data/" + month + "SalesData.txt";
    ifstream inputFile(filename);

 
        if (!inputFile.is_open()) {
            throw invalid_argument("Couldn't open file: " + filename);
        }
        else {
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
            setNumDays(monthNum);
            inputFile.close();
        }
}

string SalesPrediction::setMonth() {
    //Get the month number from the first character of the first date in the salesDataDate array
    cout << "Enter the month number for the sales data: ";
    cin >> monthNum;
        while (cin.fail() || monthNum < 1 || monthNum > 12) { //if cin is in a fail state, clear and ignore input and prompt user to enter valid input
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a valid number between 1 and 12: ";
            cin >> monthNum;
        }

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
    currentMonth = month;
    return month;
}

void SalesPrediction::setNumDays(int month) {
    //Set the number of days in the month

    int year = stoi(salesDataDate[0].substr(4, 4)); //year for leap year calculation
    switch (month)
    {
        case 1:
            numDays = 31;
            break;
        case 2:
            //Check if the year is a leap year
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
    //print the salesDataHeader array
    cout << endl << endl << "Sales Data for " << currentMonth << endl << "-----------------------" << endl;
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
    //This function calulates the total sales, average sales, highest and lowest sales, and calls the predictSales function to calculate the predicted sales for the next month
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
        cout << "Average Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << averageSalesType[typeCount] << endl;
        cout << "Highest Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << highestSalesType[typeCount] << " on " << salesDataDate[highestSalesTypeDay[typeCount]] << endl;
        cout << "Lowest Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << lowestSalesType[typeCount] << " on " << salesDataDate[lowestSalesTypeDay[typeCount]] << endl;
        cout << "Total Sales for " << salesDataHeader[typeCount + 1] << ": " << totalSalesType[typeCount] << endl;
        cout << "Predicted Sales for " << salesDataHeader[typeCount + 1] << " next month: " << predictedSales[typeCount] << endl << endl;
    }
}

void SalesPrediction::predictSales() {
    //Predict the sales for the next month using a rudiemntary algorithm
    int monthNum = stoi(salesDataDate[0].substr(0, 1));
    float predModifier = 1;  //Modifier for the predicted sales

    //As sales should increase in the summer months, decrease in the fall, and stay relatively stable otherwise, 
    //the modifier will be adjusted based on the month.
    //Current logic is to increase sales for the next month by 10% in March, 20% in April and May, 30% in June, and decrease by 10% in August, September, and October
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
        case 10:
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

void SalesPrediction::outputSalesData() {
    //Output the sales data to a file
    string filename = "./output/" + currentMonth + "Analysis.txt";
    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        throw invalid_argument("Couldn't write file: " + filename);
    }
    else {
        //Output the sales data to the file
        outputFile << setw(12) << "Sales Data for " << currentMonth << endl << "-----------------------" << endl;

        for (typeCount = 0; typeCount < 6; typeCount++) {
            outputFile << setw(12) << salesDataHeader[typeCount];
        }

        outputFile << endl;
        for (int dateCount = 0; dateCount < numDays; dateCount++) {
            for (int typeCount = 0; typeCount < 6; typeCount++) {
                if (typeCount == 0) {
                    outputFile << setw(12) << salesDataDate[dateCount];
                }
                else {
                    outputFile << setw(12) << salesData[typeCount - 1][dateCount];
                }
            }
            outputFile << endl;
        }

        //Output the sales analysis to the file
        outputFile << endl << endl << "Sales Analysis for " << currentMonth << endl << "-----------------------" << endl;
        outputFile << "Total Sales for " << currentMonth << ": " << totalSales << endl;
        outputFile << "Average Daily Sales for " << currentMonth << ": " << averageSales << endl;
        outputFile << "Highest Daily Sales for " << currentMonth << ": " << highestSales << " on " << salesDataDate[highestSalesDay] << endl;
        outputFile << "Lowest Daily Sales for " << currentMonth << ": " << lowestSales << " on " << salesDataDate[lowestSalesDay] << endl << endl;
        
        outputFile << "Sales Analysis by Type - Ice Cream is per gallon/Cones is per case" << endl << "-----------------------" << endl;
        for (int typeCount = 0; typeCount < 5; typeCount++) {
            outputFile << "Average Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << averageSalesType[typeCount] << endl;
            outputFile << "Highest Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << highestSalesType[typeCount] << " on " << salesDataDate[highestSalesTypeDay[typeCount]] << endl;
            outputFile << "Lowest Daily Sales for " << salesDataHeader[typeCount + 1] << ": " << lowestSalesType[typeCount] << " on " << salesDataDate[lowestSalesTypeDay[typeCount]] << endl;
            outputFile << "Total Sales for " << salesDataHeader[typeCount + 1] << ": " << totalSalesType[typeCount] << endl;
            outputFile << "Predicted Sales for " << salesDataHeader[typeCount + 1] << " next month: " << predictedSales[typeCount] << endl << endl;
        }
        outputFile.close();
    }
}

