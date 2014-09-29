#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )

using namespace std;

double m [1001][1001];

int main(){
	int w,b;
	scanf("%d%d",&w,&b);
	F(i,0,w+1) F(j,0,b+1){
		if(i==0) m[i][j] = 0;
		else if(j==0) m[i][j] = 1;
		else if(i==1 && j==1) m[i][j] = 0.5;
		else{
			double l = i; double k = j;
			m[i][j] = l/(l + k) + k/(l + k) * (k-1)/(l + k-1) * ((k-2)/(l + k - 2) * m[i][j-3] + l/(l + k -2) * m[i-1][j-2]);
		} 
	}
	printf("%.9lf\n",m[w][b]);
	return 0;
}