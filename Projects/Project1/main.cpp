//Project1 Riley Busche Due: 2-25-19
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

void output(list<list<int> *> outer_list, int list_counter){
    cout << "List counter: " << list_counter << endl;
    cout << "Size of outer list: " << outer_list.size() << endl;
    
    int outer_itter = 0;
    int outerListNumber = 1;
    while(outer_itter != outer_list.size()){
        list<int> *inner_list = outer_list.front();
        cout << "List " << outerListNumber << " has ";
        int sum = 0;
        int listSize = inner_list->size();
        while(!inner_list->empty()){
            sum += inner_list->front();
            inner_list->pop_front();
        }
        outerListNumber++;
        cout << listSize << " elements and sums to " << sum << endl;
        //cout << outer_list.front().size() << " elements and sums to " << sum << endl;
        outer_list.pop_front();
        delete inner_list;
    }
}

//This is a test function to validate that the numbers are being stored into list correctly
void printList(list<list<int> > outer_list){
    int outer_itter = 0;
    while(outer_itter != outer_list.size()){
        list<int> inner_list = outer_list.front();
        cout << "List size: " << inner_list.size() << endl;
        int inner_itter = 0;
        while(inner_itter != inner_list.size()){
            cout << inner_list.front() << " ";
            inner_list.pop_front();
        }
        cout << endl;
        outer_list.pop_front();
    }
}

int main(int argc, char *argv[]){
    //Checking if the correct input is given to program
    if (argc != 2){
        cerr << "Must provide name of input file." << endl;
        return 1;
    } 

    //Pulling in file
    string fileName = argv[1];
    ifstream newFile;
    newFile.open(fileName);

    //Checking if file was opened corretly
    if(!newFile){
        cerr << "Unable able to open " << fileName << endl;
        return 1; 
    }

    // Not going to end of the string, stops one number before.
    // int index = 1;
    // while ((index = line.find(" ")) != string::npos){
    //     inner_list.push_back(stoi(line.substr(0, index)));
    //     line.erase(0, index + 1);
    // }

    list<list<int> *> outer_list;
    int list_counter = 0;
    //Constructing List of Lists
    while(newFile){
        list<int> *inner_list = new list<int>;
        string line;
        getline(newFile, line);

        for(int i = 0; i < line.length(); i++){
            if (line[i] != ' '){
                inner_list->push_back((int)line[i] - 48);
            }
        }
        if((*inner_list).front() != '\0'){
            list_counter++;
            outer_list.push_back((inner_list));
        }
    }   
    //printList(outer_list);

    output(outer_list, list_counter);
    newFile.close();
    return 0;
}