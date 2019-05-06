#include <ctime>
#include <cstdlib>
#include <curses.h>

#include "drop.hpp"

Drop::Drop(){
    age = 0;
    center.c = rand() % (COLS - 2) + 1;
    center.l = rand() % (LINES - 2) + 1;
}

void Drop::Draw(){
    if (age == 0){
        mvaddch(center.l, center.c, 'o');
    }
    else if (age == 1){
        mvaddch(center.l + 1, center.c, '-');
        mvaddch(center.l, center.c - 1, '(');
        mvaddch(center.l, center.c + 1, ')');
        mvaddch(center.l - 1, center.c, '-');
    }
    else if (age == 2) {
        mvaddch(center.l + 2, center.c, '-');

        mvaddch(center.l + 1, center.c - 1, '\\');
        mvaddch(center.l + 1, center.c + 1, '/');

        mvaddch(center.l, center.c - 2, '(');
        mvaddch(center.l, center.c + 2, ')');

        mvaddch(center.l - 1, center.c - 1, '/');
        mvaddch(center.l - 1, center.c + 1, '\\');
        
        mvaddch(center.l - 2, center.c, '-');
    }
    age++;
}

bool Drop::TimeToDie(){
    if (age == MAXIMUM_AGE){
        return true;
    }
    return false;
}

void Storm::Birth(){
    // rand num 1-12
    srand((unsigned)time(0));
    int storm_size = (rand()%12)+1;
    for (int i = 0; i < storm_size; i++){
        // Drop temp = Drop();
        drops.push_back(Drop());
    }
}

void Storm::Draw(){
    // Draw entire queue
    for(int i = 0; i < drops.size(); i++){
        drops[i].Draw();
    }
}

void Storm::Cull(){
    //look at first drop, pop off if age = 3
    int i = 0;
    while (true){
        if (drops[i].TimeToDie()){
            drops.pop_front();
            i = 0;
            continue;
        }
        else {
            break;
        }
        
    }
}

