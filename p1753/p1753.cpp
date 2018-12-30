/*
 * p1753.cpp
 *
 *  Created on: Dec 30, 2018
 *      Author: zhaohankai
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

bool finish;
bool board[5][5];
int maxdepth;
void checkboard() {
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			if (board[i][j]!=board[1][1])
				return;
	finish=true;
}

void flip(int x,int y) {
	if (y>1) board[x][y-1]=!board[x][y-1];
	if (y<4) board[x][y+1]=!board[x][y+1];
	if (x>1) board[x-1][y]=!board[x-1][y];
	if (x<4) board[x+1][y]=!board[x+1][y];
	board[x][y]=!board[x][y];
}

void work(int x,int y,int dep) {
	if (dep==maxdepth) {
		checkboard();
		return;
	}
	if (x>4 || finish) return;
	flip(x,y);
	if (y<4) work(x,y+1,dep+1);
	else work(x+1,1,dep+1);
	flip(x,y);
	if (y<4) work(x,y+1,dep);
	else work(x+1,1,dep);
}

int main() {
	char ch;
	finish=false;
	for (int i=1;i<=4;i++) {
		for (int j=1;j<=4;j++){
			cin>>ch;
			if (ch=='w') board[i][j]=true;
			else board[i][j]=false;
		}
	}
	for (int i=0;i<=16;i++) {
		maxdepth=i;
		work(1,1,0);
		if (finish) break;
	}
	if (finish) {
		printf("%d\n",maxdepth);
	} else {
		printf("Impossible\n");
	}
	return 0;
}



