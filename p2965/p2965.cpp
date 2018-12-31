/*
 * p2965.cpp
 *
 *  Created on: Dec 31, 2018
 *      Author: zhaohankai
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

bool finish;
bool board[5][5];
int maxdepth;
int result[17][2];
int ans[17][2];
int len,l;
void checkboard() {
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			if (board[i][j]!=true)
				return;
	len=l;
	for (int i=0;i<len;i++) {
		ans[i][0]=result[i][0];
		ans[i][1]=result[i][1];
	}
	finish=true;
}

void flip(int x,int y) {
	for (int i=1;i<=4;i++) {
		board[i][y]=!board[i][y];
		board[x][i]=!board[x][i];
	}
	board[x][y]=!board[x][y];
}

void work(int x,int y,int dep) {
	if (dep==maxdepth) {
		checkboard();
		return;
	}
	if (x>4 || finish) return;
	flip(x,y);
	result[l][0]=x;
	result[l][1]=y;
	l++;
	if (y<4) work(x,y+1,dep+1);
	else work(x+1,1,dep+1);
	flip(x,y);
	l--;
	if (y<4) work(x,y+1,dep);
	else work(x+1,1,dep);
}

int func(string s) {
	int t,len=s.length();
	for (int i=0;i<s.length();i++)
		t=t*10+s[i]-'0';
	return t;
}

int main() {
	/*
	char ch;
	finish=false;
	for (int i=1;i<=4;i++) {
		for (int j=1;j<=4;j++){
			cin>>ch;
			if (ch=='-') board[i][j]=true;
			else board[i][j]=false;
		}
	}
	for (int i=0;i<=16;i++) {
		maxdepth=i;
		l=0;
		memset(result,0,sizeof(result));
		work(1,1,0);
		if (finish) break;
	}
	if (finish) {
		printf("%d\n",maxdepth);
		for (int i=0;i<len;i++)
			printf("%d %d\n",ans[i][0],ans[i][1]);
	} else {
		printf("Impossible\n");
	}*/
	cout<<func("1234533")<<endl;
	return 0;
}



