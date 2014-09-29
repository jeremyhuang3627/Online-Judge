#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int t [5005],n,m,mx=1;
double d [5005];
int l [5005];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n + 1) scanf("%d%lf",&t[i],&d[i]);	
	F(i,1,n + 1) l[i] = 1; 
	F(i,1,n + 1) F(j,1,i) if(t[j] <= t[i] && l[j] + 1 > l[i]) l[i] = l[j] + 1,mx = max(mx,l[i]);
	cout << n - mx << endl;
	return 0;
}