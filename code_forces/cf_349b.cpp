#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1000005

using namespace std;

int a[10],v,s=M,l;

int main(){
	scanf("%d",&v);
	F(i,0,9){
		scanf("%d",&a[i]);
		s = min(s,a[i]);
	}
	l = v/s;
	if(!l) cout << -1 << endl;
	else while(l--) for(int i=8;i>=0;i--) if((v-a[i])/s==l && v >= a[i] ){
			v-= a[i];cout << i + 1;break;
		}
	cout << endl;
	return 0;
}