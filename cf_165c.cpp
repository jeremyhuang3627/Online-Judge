#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1005
#define MX 1000005

using namespace std;

int k,d[MX][MX],l,cnt=0;
char c [MX];

int main(){
	scanf("%d",&k);
	scanf("%s",c);
	l = strlen(c);
	F(i,0,l) F(j,0,l){
			if(j>0) d[i][j] = i<=j ? d[i][j-1] + (c[j]=='1') : 0;
			else d[i][j] = i==j ? c[j] == '1' : 0;
			//cout << "d["<< i <<"][" << j << "] " << d[i][j] << endl;
			if(d[i][j] == k) cnt++;
	}
	cout << cnt << endl;
	return 0;
}