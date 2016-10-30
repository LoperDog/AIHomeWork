#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#define STARTX 1
#define ENDX 41
#define STARTY 1
#define ENDY 20

using namespace std;
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
class super {
	// 
protected:
	int x, y;
	int mvx, mvy;
	string self;
	int runtime;

public : 
	super() {}
	~super() {}
	virtual void run() = 0;
	void display() {
		gotoxy(x, y);
		cout << self;
	}
	void earse() {
		gotoxy(x, y);
		cout << "  ";
	}
};

class triangle : public super {
private :
public :
	triangle() {
		x = ENDX;
		y = STARTY;
		self = "▲";
		display();
	}
	~triangle() {}
	void run() {
		earse();
		// 만약 끝에 닿았다면.
		if (x >= ENDX && y <= STARTY) {
			mvx = -2;
			mvy = 1;
		}
		else if (x <= STARTX && y >= ENDY) {
			mvx = 0;
			mvy = -1;
		}
		else if (x <= STARTX && y <= STARTY) {
			mvx = 2;
			mvy = 0;
		}
		x += mvx;
		y += mvy;

		display();
	}
};
class sircle : public super {
public:
	sircle() {
		x = STARTX;
		y = STARTY;
		mvx = 2;
		mvy = 1;
		self = "●";

		display();
	}
	~sircle() {}
	void run() {
		earse();
		if (x >= ENDX && y <= STARTY) {
			mvx = 0;
			mvy = 1;
		}
		else if (x <= STARTX && y >= ENDY) {
			mvx = 0;
			mvy = -1;
		}
		else if (x <= STARTX && y <= STARTY) {
			mvx = 2;
			mvy = 0;
		}
		else if (x >= ENDX && y >= ENDY) {
			mvx = -2;
			mvy = 0;
		}
		x += mvx;
		y += mvy;
		display();
	}
};

class star : public super {
public:
	star() {
		x = ENDX;
		y = ENDY;
		mvx = -2;
		mvy = -1;
		self = "★";
		display();
	}
	~star() {}

	void run() {
		earse();
		if (x >= ENDX && y <= STARTY) {
			mvx = -2;
			mvy = 0;
		}
		else if (x <= STARTX && y >= ENDY) {
			mvx = 2;
			mvy = 0;
		}
		else if (x <= STARTX && y <= STARTY) {
			mvx = 0;
			mvy = 1;
		}
		else if (x >= ENDX && y >= ENDY) {
			mvx = 0;
			mvy = -1;
		}
		x += mvx;
		y += mvy;
		display();
	}
};

int main(void) {

	super * tri = new triangle();
	super * sir = new sircle();
	super * str = new star();

	while (true) {
		Sleep(100);
		tri->run();
		sir->run();
		str->run();
	}

	return 0;
}