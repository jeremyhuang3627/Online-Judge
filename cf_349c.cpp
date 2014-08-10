#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1000005

using namespace std;

int a[10],v,m=0,idx=-1;

int main(){
	scanf("%d",&v);
	F(i,1,10){
		scanf("%d",&a[i]);
		if(v/a[i]>=m){
			m = v/a[i];
			idx = i;
		}
	}
	if(!m){
		cout << -1 << endl;
	}else{
		F(i,0,m) cout << idx << "";	
		cout << endl;
	}
	return 0;
}