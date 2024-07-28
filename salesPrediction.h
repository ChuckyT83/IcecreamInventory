#include <iostream>

using namespace std;

class SalesPrediction {
    public:
        void salesPrediction(); //Function declaration that includes all functions neccessary for sales prediction
    private:
        string setMonth(); //Function declaration for setting the month
        void parseSalesData(string month); //Function declaration for parsing the sales data
        void printSalesData(); //Function declaration for printing the sales data
        void salesAnalysis(); //Function declaration for analyzing the sales data
        void printSalesAnalysis(); //Function declaration for printing the sales analysis
        void predictSales(); //Function declaration for predicting the sales of the month after the current month
        void setNumDays(int month); //Function declaration for setting the number of days in the month
        void outputSalesData(); //Function declaration for outputting the sales data to a file
        string salesDataHeader[6]; //Array to hold the header data from the sales data file
        string salesDataDate[31]; //Array to hold the date data from the sales data file
        int salesData[5][31]; //Array to hold the sales data from the sales data file
        int dateCount; //Counter for the date array
        int typeCount; //Counter for the sales data array. Used to move through each item type in the sales data array.
        int totalSales = 0; //Total sales for the month
        int totalDays = 0; //Counter for the total number of days in the month
        int averageSales = 0; //Average sales for the month
        int highestSales = 0;  //Highest sales for the month
        int highestSalesDay = 0; //Day of the highest sales for the month
        int lowestSales = 0; //Lowest sales for the month
        int lowestSalesDay = 0; //Day of the lowest sales for the month
        int totalSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the total sales for each type of ice cream/cone
        int averageSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the average sales for each type of ice cream/cone
        int highestSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the highest sales for each type of ice cream/cone
        int highestSalesTypeDay[5] = {0, 0, 0, 0, 0}; //Array to hold the day of the highest sales for each type of ice cream/cone
        int lowestSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the lowest sales for each type of ice cream/cone
        int lowestSalesTypeDay[5] = {0, 0, 0, 0, 0}; //Array to hold the day of the lowest sales for each type of ice cream/cone
        int predictedSales[5] = {0, 0, 0, 0, 0}; //Array to hold the predicted sales for each type of ice cream/cone
        int tempSales = 0; //Temporary variable to hold the sales data for calculations
        int numDays; //Number of days in the month
        int monthNum; //Number of the month
        string currentMonth; //Current month
        
};