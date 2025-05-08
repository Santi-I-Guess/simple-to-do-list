#include <stdio.h>
#include <curses.h>
#include <panel.h>

int main() {
        
        initscr():
        cbreak();
        noecho();
        raw();
        
        

        bkgd(' ' | COLOR_PAIR(1));

        refresh();
        int something = getch();

        endwin()

        return 0;
}
