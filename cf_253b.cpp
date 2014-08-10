#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1005
#define MX 100005

using namespace std;

int n,a[MX],j=1,k=MX;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	F(i,1,n + 1){
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n +1);
	F(i,1,n+1){
		while(j<n && a[j+1] <= 2*a[i]) j++;
		k = min(k,i+n-j-1);
	}
	cout << k << endl;
	return 0;
}