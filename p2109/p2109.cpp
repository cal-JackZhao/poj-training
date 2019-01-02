/*
 * p2109.cpp
 *
 *  Created on: Jan 1, 2019
 *      Author: zhaohankai
 */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n;
	double p;
	while (scanf("%d%lf",&n,&p)!=EOF) {
		printf("%.0lf\n",pow(p,1.0/n));
	}
	return 0;
}



