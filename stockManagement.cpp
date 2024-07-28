#include "stockManagement.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

float chocolateStock = 0;
float vanillaStock = 0;
float strawberryStock = 0;

void loadStockData() {
    ifstream inputFile("stockData.txt");
    if (inputFile.is_open()) {
        inputFile >> chocolateStock >> vanillaStock >> strawberryStock;
        inputFile.close();
    } else {
        // File does not exist or cannot be opened, initializing to default values.
        chocolateStock = 0;
        vanillaStock = 0;
        strawberryStock = 0;
    }
}

void saveStockData() {
    ofstream outputFile("stockData.txt");
    if (outputFile.is_open()) {
        outputFile << chocolateStock << endl
                   << vanillaStock << endl
                   << strawberryStock << endl;
        outputFile.close();
    } else {
        cerr << "Error opening file to save stock data." << endl;
    }
}

void inputCurrentStock() {
    cout << "Enter current stock for Chocolate (in pounds): ";
    cin >> chocolateStock;
    cout << "Enter current stock for Vanilla (in pounds): ";
    cin >> vanillaStock;
    cout << "Enter current stock for Strawberry (in pounds): ";
    cin >> strawberryStock;
    saveStockData(); // Save updated stock data
    cout << "Stock updated successfully!" << endl;
}

void orderMoreStock() {
    float chocolateOrder, vanillaOrder, strawberryOrder;

    cout << "Enter additional stock to order for Chocolate (in pounds): ";
    cin >> chocolateOrder;
    cout << "Enter additional stock to order for Vanilla (in pounds): ";
    cin >> vanillaOrder;
    cout << "Enter additional stock to order for Strawberry (in pounds): ";
    cin >> strawberryOrder;

    // Update stock with the new order
    chocolateStock += chocolateOrder;
    vanillaStock += vanillaOrder;
    strawberryStock += strawberryOrder;

    saveStockData(); // Save updated stock data
    cout << "Stock ordered successfully!" << endl;
}

void unitConverter() {
    int choice;
    cout << "Select the unit to convert to:" << endl;
    cout << "1. Quarts" << endl;
    cout << "2. Pints" << endl;
    cout << "3. Grams" << endl;
    cin >> choice;

    float conversionFactor;
    switch (choice) {
        case 1:
            conversionFactor = 1.06;  // 1 pound = 1.06 quarts
            break;
        case 2:
            conversionFactor = 2.11;  // 1 pound = 2.11 pints
            break;
        case 3:
            conversionFactor = 453.592;  // 1 pound = 453.592 grams
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }

    cout << fixed << setprecision(2);
    cout << "Chocolate: " << chocolateStock * conversionFactor << " in selected unit." << endl;
    cout << "Vanilla: " << vanillaStock * conversionFactor << " in selected unit." << endl;
    cout << "Strawberry: " << strawberryStock * conversionFactor << " in selected unit." << endl;
}

void viewCurrentStock() {
    loadStockData();  // Load the current stock data from file

    cout << fixed << setprecision(2);
    cout << "Current Stock:" << endl;
    cout << "Chocolate: " << chocolateStock << " pounds" << endl;
    cout << "Vanilla: " << vanillaStock << " pounds" << endl;
    cout << "Strawberry: " << strawberryStock << " pounds" << endl;
}