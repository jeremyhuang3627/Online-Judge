#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define LL long long
#define N 105

using namespace std;

int a[N][N];
int b[N],n,m=0,cnt=0;


int main(){
	cin >> n;
	F(i,0,n){
		cin >> b[i];
		if(b[i]) cnt++;
	}

	F(i,0,n){
		for(int j=i;j>=0;j--){
			if(i==j){
				a[i][j] = (b[j] == 0);
			}else{
				a[i][j] = a[i][j+1] + (b[j] == 0);
			}
			int n_ones = cnt - (i - j + 1 - a[i][j]);
			m = max(a[i][j] + n_ones ,m);
		}
	}
	cout << m << endl;

	return 0;
}

