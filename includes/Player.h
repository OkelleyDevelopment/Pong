#ifndef PONG_PLAYER
#define PONG_PLAYER

#include <ncurses.h>

class Player {

public:
  Player(int x, int y);

  // Getters
  int get_X() { return x; }
  int get_Y() { return y; }
  int getHeight() { return height; }

  // Setters
  void set_X(int a) { x = a; }
  void set_Y(int b) { y = b; }

  // Display
  void drawPlayer(int x, int y) {
    mvaddch(y + 2, x, '|');
    mvaddch(y + 1, x, '|');
    mvaddch(y, x, '|');
    mvaddch(y - 1, x, '|');
    mvaddch(y - 2, x, '|');
  }

private:
  int x, y, height;
};

#endif /* ifndef PONG_PLAYER */
