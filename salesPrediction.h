#include <iostream>

using namespace std;

class SalesPrediction {
    public:
        void salesPrediction();
        string setMonth();
        void parseSalesData(string month);
        void printSalesData();
        void salesAnalysis();
        void printSalesAnalysis();
        void predictSales();
        void setNumDays(int month);
    private:
        string salesDataHeader[6]; //Array to hold the header data from the sales data file
        string salesDataDate[31]; //Array to hold the date data from the sales data file
        int salesData[5][31]; //Array to hold the sales data from the sales data file
        int dateCount; //Counter for the date array
        int typeCount; //Counter for the sales data array
        int totalSales = 0;
        int totalDays = 0;
        int averageSales = 0;
        int highestSales = 0;
        int highestSalesDay = 0;
        int lowestSales = 0;
        int lowestSalesDay = 0;
        int totalSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the total sales for each type of ice cream/cone
        int averageSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the average sales for each type of ice cream/cone
        int highestSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the highest sales for each type of ice cream/cone
        int highestSalesTypeDay[5] = {0, 0, 0, 0, 0}; //Array to hold the day of the highest sales for each type of ice cream/cone
        int lowestSalesType[5] = {0, 0, 0, 0, 0}; //Array to hold the lowest sales for each type of ice cream/cone
        int lowestSalesTypeDay[5] = {0, 0, 0, 0, 0}; //Array to hold the day of the lowest sales for each type of ice cream/cone
        int predictedSales[5] = {0, 0, 0, 0, 0}; //Array to hold the predicted sales for each type of ice cream/cone
        int tempSales = 0;
        int numDays;
        int monthNum;
        string currentMonth;
        
};