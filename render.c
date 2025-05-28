#include "includes.h"

const char * s_ct = "┼";
const char * s_vert = "│";
const char * s_hor = "─";

const int coef = 2;
const int cell_size = 10;

int render_thread()
{
	return 0;
}

void render_bg_grid(int rows, int cols)
{
	attron(COLOR_PAIR(1));

	for (int c = 0; c < (cols * coef); c++) {
		for (int r = 0; r < rows; r++) {
			if ((r+pos_y)%cell_size == 0 ) { mvprintw(r, c, "%s", s_hor); }
			if ((c+pos_x)%(cell_size*coef) == 0 ) { mvprintw(r, c, "%s", s_vert); }
			if ((r+pos_y)%cell_size == 0 && (c+pos_x)%(cell_size*coef) == 0) { mvprintw(r, c, "%s", s_ct); }
		}
	}

	attroff(COLOR_PAIR(1));
}

void pairs_init()
{
	init_pair(1, 8, -1);
}

int ncurses_init()
{
    setlocale(LC_ALL, "");

    initscr();

    if (!has_colors())
	{  
        endwin();
        printf("Term colors not supported. Exiting.\n");

		return -1;
    }
	else
	{
		start_color();  
		use_default_colors();  
	}

    cbreak(); 
    noecho();
    keypad(stdscr, TRUE); 
	curs_set(0);

	pairs_init();

	return 0;
}

void ncurses_final()
{
    refresh();

    getch();

    endwin();
}
