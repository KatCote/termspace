#ifndef __KTC_PROTO_GUARD__
#define __KTC_PROTO_GUARD__

// render.c

int render_thread();

void render_bg_grid(int, int);

int ncurses_init();
void ncurses_final();

// control.c

int control_thread();

#endif
