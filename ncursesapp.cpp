#include <iostream>
#include "webncurses.h"
#include <string.h>

using namespace std;

int main() {
  char foo[2];
  string output = "Hello World!";
  string output2 = "I'm an ncurses app!";
  WINDOW * main = initscr();
  mvaddstr(5, 5, output.c_str());
  system("sleep 3");
  foo[0] = getch();
  foo[1] = '\0';
  mvaddstr(10, 10, foo);
  refresh();
  system("sleep 10");
  endwin();
  delwin(main);
  return 0;
}
