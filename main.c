#include <stdio.h>
#include <curses.h>
#include <panel.h>

int main() { 
        // background initialization
        initscr();
        cbreak();
        noecho();
        raw();
        curs_set(0); 
        start_color();
        init_pair(1, 0, 235); // background
        init_pair(2, 0, 236); // footer & focus
        init_pair(3, 0, 21); // bright blue

        wbkgd(stdscr, ' ' | COLOR_PAIR(1));
        int max_y, max_x;
        getmaxyx(stdscr, max_y, max_x);

        // footer initialization
        WINDOW *footer_win = newwin(2, max_x, max_y-2, 0);
        PANEL *footer_panel = new_panel(footer_win);
        wbkgd(footer_win, ' ' | COLOR_PAIR(2));

        // focus initialization
        WINDOW *focus_win = newwin((3*max_y)/5, (3*max_x)/5, max_y/5, max_x/5);
        PANEL *focus_panel = new_panel(focus_win);
        wbkgd(focus_win, ' ' | COLOR_PAIR(2));

        update_panels();
        doupdate();
        refresh();
        int something = getch();
        
        del_panel(footer_panel);
        del_panel(focus_panel);
        delwin(footer_win);
        delwin(focus_win);
        endwin();

        printf("%d %d\n", max_y, max_x);

        return 0;
}
