#pragma once
#include <map>
#include <string>

using namespace std;

class Purchase {
public:
    Purchase(string id, string invoice, string date, float amount){
        mId = id;
        mInvoice = invoice;
        mDate = date;
        mAmount = amount;
    }
    
    string mId;
    string mInvoice;
    string mDate;
    float mAmount;
};
