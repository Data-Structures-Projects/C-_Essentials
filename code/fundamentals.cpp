#include "fundamentals.hpp"

void insertStockInfo(stockInfo stocks[], string company_name, double stock_prices_arr[], int index) {
    // TODO
    //initialize newStock
    stockInfo newStock;
    newStock.company_name = company_name;
    //set stock price arrays to each other
    for(int i = 0; i < 5; i++){
        newStock.stock_prices_arr[i] = stock_prices_arr[i];
    }
    //find average stock price
    double sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += stock_prices_arr[i];
    }
    double average = sum/5;
    newStock.average = average;
    //end setting up newStock Struct
    stocks[index] = newStock;

    return;
}

void displaySortedStocks(stockInfo stock, ofstream& file){
    // TODO
    // sort the stock prices
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (stock.stock_prices_arr[j] > stock.stock_prices_arr[j + 1]) {
                // Swap the elements
                double temp = stock.stock_prices_arr[j];
                stock.stock_prices_arr[j] = stock.stock_prices_arr[j + 1];
                stock.stock_prices_arr[j + 1] = temp;
            }
        }
    }
    // print to terminal
    cout << stock.company_name << "," << stock.average << ",";
    for (int i = 0; i < 5; i++) {
        cout << stock.stock_prices_arr[i];
        if (i < 4) {
            cout << ",";
        }
    }
    cout << endl;

    //print to file
     file << stock.company_name << "," << stock.average << ",";
    for (int i = 0; i < 5; i++) {
        file << stock.stock_prices_arr[i];
        if (i < 4) {
            file << ",";
        }
    }   
    file << endl;


    return;
}