#pragma once
#include <string>
#include <map>

using namespace std;

class Customer {
public:
    Customer(string id, string name, string street, string city, string state, string zipcode){
        mId = id;
        mName = name;
        mStreet = street;
        mCity = city;
        mState = state;
        mZipcode = zipcode;
    }

    string mId;
    string mName;
		string mStreet;
		string mCity;    
		string mState;
    string mZipcode;
};