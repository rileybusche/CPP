#include<map>
#include<utility>
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Node {
    public:
        Node() {
            frequency = 1;
        }
        int frequency;
        vector<int> appears_on_lines;
};

int main(int argc, char * argv[]){
    // map<string, Node> words;
    
    // Node n;
    // words.emplace("dog", n);

    // Node x;
    // x.frequency = 3;
    // words.emplace("cat", x);

    // Node index = words.at("cat");

    // cout << index.frequency << endl;

    
    string input;

    // do {
    //     cout << "Enter something: ";
    //     string output;
    //     cin >> output;
    //     cout << output << endl;
    // } while(cin >> input);
    // cout << "Enter something: ";
    // while(cin >> input){
    //     cout << input << endl;
    //     cout << "Enter something: ";
    // }
    vector<int> lines;
    lines.push_back(1);
    lines.push_back(2);
    lines.push_back(3);
    lines.push_back(4);
    lines.push_back(5);
    lines.push_back(6);

    for(auto lineNum : lines){
        cout << lineNum;
    }
    cout << endl;

}