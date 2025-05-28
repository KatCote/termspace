#include "includes.h"

int main()
{
	int retcode = 0;

	if ((retcode = ncurses_init()) != 0)
	{ return -1; }
    
    clear();
 
    int row, col;
    getmaxyx(stdscr, row, col);
		
	render_bg_grid(row, col);

	ncurses_final();

    return 0;
}
