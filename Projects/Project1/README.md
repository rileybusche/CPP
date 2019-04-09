README for project one

1. Open file        #include <fstream>
2. Verify Open      inp.is_open() <- boolean returning if file is open
3. Read it
4. Close it


argc ≥ 1

    ./a.out BADFILE -> argc = 2

int main(int argc; char *argv[]){
    
}

fstream and iostream inherits from "stream"


check if argc is atleast 2
if argc = 2 {
    ifstream inp(argv[1]);
}



Vector containing pointers to lists containing integers
    - 2D array essentially

    using "new" to dynamically create more instancs
        -delete after use (at end)

    -vector<vector<int>> out "but do not do this since Perrry said so"