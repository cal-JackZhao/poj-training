/*
 * p1328.cpp
 *
 *  Created on: Dec 31, 2018
 *      Author: zhaohankai
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct coord {
	double x,y;
};
coord a[2000];
bool cmp(coord o1, coord o2) {
	return o1.x>o2.x;
}

int main() {
	int n,d,num=0,tx,ty;
	while (scanf("%d%d",&n,&d) && (n!=0 || d!=0)) {
		num++;
		bool f=false;
		for (int i=0;i<n;i++) {
			scanf("%d%d",&tx,&ty);
			if (ty>d) {
				f=true;
			}
			double dis=sqrt(1.0*d*d-ty*ty);
			a[i].x=tx-dis;
			a[i].y=tx+dis;
		}
		if (d<0) f=true;
		if (f) {
			printf("Case %d: -1\n",num);
			continue;
		}
		sort(a,a+n,cmp);
		int ans=0;
		bool vis[2000];
		memset(vis,false,sizeof(vis));
		for (int i=0;i<n;i++) {
			if (!vis[i]) {
				vis[i]=true;
				for (int j=0;j<n;j++) {
					if (!vis[j] && a[j].y>=a[i].x) vis[j]=true;
				}
				ans++;
			}
		}
		printf("Case %d: %d\n",num,ans);
	}
	return 0;
}



