#include<map>
#include<random>                //rand() % (max-min+1)+min includes max and min
#include<string>
#include<utility>
#include<iostream>
using namespace std;

int makeRand(){
    return rand() % (100-1);
}


int main(int argc, char *argv[]){
    
    map<int, string> dict;

    for(int i = 0; i < 10; i++){
        int number = makeRand();
        dict.emplace(number, to_string(number));
        cout << "Added: " << number << endl;
    }

    // for(map<int, string>::iterator it = dict.begin(); it != dict.end; it++){
    // }
    //Auto for loop of above loop
    for(auto it = dict.begin(); it != dict.end(); it++){
        cout << "Key: " << it->first << " Value: " << it->second << endl;
    }
    
    //cout << ((some boolean statement) ? "otuput" : "output if flase") << endl;

    return 0;
}

