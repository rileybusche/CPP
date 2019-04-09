#include <iostream>
#include <curses.h>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

int main(int argc, char * argv[]){

    double two_pi = M_PI * 2;
    double increment;
    double phase_shift = 0;

    initscr();

    increment = two_pi / (COLS - 2);
    // Remove Curser
    curs_set(0);

    while(true){
        erase();
        double theta = 0;

        for (int i = 0; i < COLS - 2; i++){
            theta += increment;
            double amplitude = sin(theta + phase_shift) * 9.0;
            mvaddch(LINES / 2 - static_cast<int>(amplitude), i, '*');
        }
        phase_shift += increment;

        //mvaddch(rand() % (LINES - 2) + 1, rand() % (COLS - 2) + 1, '*');             // Does not draw behind the box now
        box(stdscr, 0, 0);
        mvaddstr(0, 2, " Riley ");
        refresh();
        // Close to 60 fps
        this_thread::sleep_for(chrono::milliseconds(16));
    }
    
    endwin();
    return 0;
}