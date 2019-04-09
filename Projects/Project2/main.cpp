//Project 2 - Riley Busche Due: 3/4/19
#include<map>
#include<utility>
#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

//MARK: - Data Type
class Node {
    public:
        Node() {
            frequency = 1;
        }
        int frequency;
        vector<int> appears_on_lines;
};

//MARK: - Output function
void printOutPut(map<string, Node> words, string searchWord){
    cout << searchWord << " found " << words.at(searchWord).frequency << " times on lines:" << endl;
    vector<int> lines = words.at(searchWord).appears_on_lines;
    for(auto lineNum : lines){
        if(lineNum == lines[lines.size()-1]){
            cout << lineNum;
        } else {
            cout << lineNum << ", ";
        }
    }
    cout << endl;
}

int main(int argc, char * argv[]){
    map<string, Node> words;

    //MARK: - Open and Check file
    if (argc != 2){
        cerr << "Must provide word file name." << endl;
        return 1;
    } 
    
    ifstream inFile;
    inFile.open(argv[1]);

    if(!inFile){
        cerr << "Could not open: " << argv[1] << endl;
        return 1; 
    }
    //MARK: - Build Map (loop through file)
    string line;
    int lineNumber = 0;
    int loopCount;
    while(getline(inFile, line)){
        lineNumber++;
        auto it = words.find(line);
        if (it == words.end()) {
            //Word not in list - add to map
            Node n;
            words.emplace(line, n);
            words.at(line).appears_on_lines.push_back(lineNumber);
        } else {
            //Word is in list - append line number and increment frequency
            words.at(line).frequency++;
            words.at(line).appears_on_lines.push_back(lineNumber);
        }
    }

    //MARK: - User Input
    cout << "Enter a word (case sensititive): ";
    string searchWord;
    while(cin >> searchWord){
        auto it = words.find(searchWord);
        if (it == words.end()) {
            //Word is not in map
            cout << "Could not locate: " << searchWord << endl;
        } else {
            //Word is in map
            printOutPut(words, searchWord);
        }
        cout << "Enter a word (case sensititive): ";
    }    

    return 0;   
}