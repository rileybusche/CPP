// Project 3 - Riley Busche Due: 3-21-19
#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include "split.hpp"
#include <iomanip>
#include "customer.hpp"
#include "purchase.hpp"
using namespace std;

//MARK: - String to Float
float StringToFloat(string input){
	float v = 0;
	try {
		v = stof(input);
	}
	catch (const invalid_argument &) {
        	return 1;
	}
	return v;
}

//Mark: - Prints out purchase information
void SumTransactions(multimap<string, Purchase> transactions, string id){
    float sum = 0;
    auto it = transactions.equal_range(id);
    int count = 0;
    cout.precision(2);
    for (auto itr = it.first; itr != it.second; ++itr) {
        sum+= itr->second.mAmount;
        count++;
    }
    cout << left << fixed << setw(11) << count << "$" << sum << endl;
}

//MARK: - Main
int main(int argc, char *argv[]){
    // Checking if the correct input is given to program
    if (argc != 3){
        cerr << "Must provide name of input files (2 files)." << endl;
        return 1;
    } 

    //MARK: - Maps
    // Apple : 12313
    map<string, string> nameWithCompID;
    // 12313 : Customer
    map<string, Customer> compIDWithAll;
    // ID : Purchase
    multimap<string, Purchase> transactions; 

    ifstream inFileCompany;
    inFileCompany.open(argv[1]);

    if(!inFileCompany){
        cerr << "Could not open: " << argv[1] << endl; 
    }

    ifstream inFileData;
    inFileData.open(argv[2]);

    if(!inFileData){
        cerr << "Could not open: " << argv[2] << endl;
    }

    string line;
    vector<string> tokens;
    string delimeter = ",";

    //Mark: - Build Maps
    while(getline(inFileCompany, line)){
        Split(tokens, line, delimeter);

        Customer customer(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);

        nameWithCompID.emplace(tokens[1], tokens[0]);
        compIDWithAll.emplace(tokens[0], customer);
    }

    //MARK: - Build Multimaps
    line.clear();
    tokens.clear();
    while(getline(inFileData, line)){
        Split(tokens, line, delimeter);

        Purchase purchase(tokens[0], tokens[1], tokens[2], StringToFloat(tokens[3]));
        
        transactions.insert({tokens[0], purchase});
    }

    cout << "File: " << argv[1] << " contained " << compIDWithAll.size() <<  " records." << endl;
    cout << "File: " << argv[2] << " contained " << transactions.size() <<  " records." << endl;
    cout << "Sales summary report:" << endl;
    cout << "=====================" << endl;
    cout << setw(10) << left << "ID:" << setw(38) << "Name:" << setw(8) << "State:" << setw(11) << "Purchases:" << "Total:" << endl;

    for (auto it = nameWithCompID.begin(); it != nameWithCompID.end(); it++){
        cout << setw(10) << it->second << setw(38) << it->first << setw(8) << compIDWithAll.find(it->second)->second.mState;
        SumTransactions(transactions, it->second);

    }

    inFileCompany.close();
    inFileData.close();

    return 0;
}