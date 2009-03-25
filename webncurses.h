#ifndef _WEBNCURSES_H_
#define _WEBNCURSES_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef ofstream WINDOW;

WINDOW mainwin;
ifstream maininwin;

WINDOW * initscr() {
  system("mkfifo main.input.win");
  system("chmod 777 main.input.win");
  string filename = "main.output.win";
  mainwin.open(filename.c_str());
  mainwin << "NEW WINDOW" << endl;
  return &mainwin;
}

void delwin(WINDOW * todel) {
  (*todel).close();
  remove("main.output.win");
  remove("main.input.win");
}

void endwin() {
  mainwin << "QUIT" << endl;
  mainwin.close();
}

void mvaddstr(int x, int y, const char* instring) {
  string temp(instring);
  mainwin << "[" << x << " " << y << "]" << " " << temp << endl;
}

void refresh() {
  // Do nothing
}

void getstr(char * dst) {
  string tmp = "";
  mainwin << "INPUT [STR]" << endl;
  maininwin.open("main.input.win");
  do {
    getline(maininwin, tmp);
  } while (tmp == "");
  maininwin.close();
  strcpy(dst, tmp.c_str());
}

char getch() {
  char tmp = '\0';
  mainwin << "INPUT [CH]" << endl;
  maininwin.open("main.input.win");
  do {
  maininwin >> tmp;
  } while(tmp == '\0');
  maininwin.close();
  return tmp;
}

void wrefresh(WINDOW * win) {
  // Do nothing
}

#endif
