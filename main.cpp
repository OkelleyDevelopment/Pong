//-----------------------------------
// Author: Nicholas O'Kelley
// Date: 2021-01-17
//-----------------------------------

#include "includes/Ball.h"
#include "includes/Player.h"
#include <ncurses.h>
#include <stdlib.h>

int WIDTH = 80;
int HEIGHT = 20;
bool isGameOver;
bool p1_serve, p2_serve = false;

int ch;
int player1Points, player2Points = 0;
int direction = 1; // direction of the ball

char wallTexture;

Player player1(2, HEIGHT / 2);
Player player2(WIDTH - 3, HEIGHT / 2);
Ball ball(HEIGHT / 2, 3, 1);

void setup_game() {
  wallTexture = '*';

  // NCurses init
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(50);

  isGameOver = false;
  player1Points = 0;
  player2Points = 0;
}

void get_input() {
  ch = getch();
  switch (ch) {
  case 'w':
    if (player1.get_Y() != 3) {
      player1.set_Y(player1.get_Y() - 1);
    }
    break;
  case 's':
    if (player1.get_Y() != HEIGHT - 4) {
      player1.set_Y(player1.get_Y() + 1);
    }
    break;
  case 'a':
    if (player1.get_X() != 2) {
      player1.set_X(player1.get_X() - 1);
    }
    break;
  case 'd':
    if (player1.get_X() != WIDTH / 2 - 4) {
      player1.set_X(player1.get_X() + 1);
    }
    break;

  case ' ':
    if (p1_serve) {
      p1_serve = false;
      direction = 1;
    } else if (p2_serve) {
      p2_serve = false;
      direction = 2;
    }
    break;

  case 'q':
    isGameOver = true;
    break;
  }
}

void draw() {
  erase();
  refresh();
  for (int i = 0; i < WIDTH; i++) {
    mvaddch(0, i, wallTexture);
    mvaddch(HEIGHT - 1, i, wallTexture);
  }

  for (int i = 1; i < HEIGHT - 1; i++) {
    mvaddch(i, WIDTH / 2, ':');
  }

  mvprintw(1, WIDTH / 2 / 2, "%i", player1Points);
  mvprintw(1, WIDTH / 2 + WIDTH / 2 / 2, "%i", player2Points);

  ball.drawBall(ball.get_X(), ball.get_Y());
  player1.drawPlayer(player1.get_X(), player1.get_Y());
  player2.drawPlayer(player2.get_X(), player2.get_Y());
}

int main() {
  setup_game();

  // Game loop
  while (!isGameOver) {
    get_input();
    // TODO: Handle game logic
    draw();
  }
  endwin();
  return 0;
}
