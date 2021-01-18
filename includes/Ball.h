#ifndef PONG_BALL
#define PONG_BALL

#include <ncurses.h>

class Ball {
public:
  Ball(double x, double y, int speed);
  // Getters
  double get_X() { return x; }
  double get_Y() { return y; }
  int get_speed() { return speed; }

  // Setters
  void set_X(double a) { x = a; }
  void set_Y(double b) { y = b; }
  void setSpeed(int s) { speed = s; }

  // Display
  void drawBall(double x, double y) { mvaddch(x, y, 'o'); }

private:
  double x, y;
  int speed;
};

#endif /* ifndef SYMBOL */
