#include <iostream>
#include <fstream>
#include "../code/fundamentals.hpp"
#include <sstream>
#include <string>
#include <vector>

using namespace std;
stockInfo stocks[50];

int main(int argc, char* argv[]) {
    // TODO
    //initilize stocks
    stockInfo initial;
    initial.average = 0;
    initial.company_name = "empty";
    vector<string> row;
    for(int i = 0; i < 5; i++){
        initial.stock_prices_arr[i] = 0;
    }
    for(int i = 0; i <50; i++){
        stocks[i] = initial;
    }
    fstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    string line;
    string data;
    int index_stocks = 0;
    string name;
    double arr[5];
    if(!inputFile.is_open()){
        cout << "input file could not be opened"<< endl;
    }
    if(!outputFile.is_open()){
        cout << "output file could not be opened" << endl;
    }



    while(getline(inputFile, line)){
        //put line into a stringStream
        stringstream str(line);
        row.clear();
        while(getline(str, data, ',')){
            row.push_back(data);
        }
        name = row.at(0);
        for(int i = 0; i < 5; i++){
            arr[i] = ::atof(row.at(i+1).c_str());
        }
        insertStockInfo(stocks, name, arr, index_stocks);
        index_stocks = index_stocks + 1;
    }
		
    for(int i = 0; i < 50; i ++){
        if(stocks[i].average != initial.average){
            displaySortedStocks(stocks[i], outputFile);
        }
    }
    
    inputFile.close();
    outputFile.close();

    return 0;
}