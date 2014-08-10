#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 200005

using namespace std;

long long n,a[M],y,v[M][2],b[M][2],s,d=0,t;

long long go(long long x,long long f){
	//cout << "x " << x << " f " << f << endl;
	if(x<1 || x>n) return 0;
	long long & r=b[x][f],&s = v[x][f];
	if(x==1 || s==d) r = -1;
	else if(!s){
		s = d;
		t = go(x + (f?-a[x]:a[x]),!f);
		r = (t==-1 ? t : t+a[x]);
	}
	return r;
}

int main(){
	cin >> n;
	F(i,2,n+1){cin >> a[i];}
	F(i,1,n){ 
		++d;
		cout << ((t=go(i+1,1))<0?-1:t+i) << endl;
	}
	return 0;
}