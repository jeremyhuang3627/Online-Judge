#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int a[100005],n,i,j,z,k;

int main()
{
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}

	for(i=1;i<=n/3;i++){
		if(n%i==0){
			for(j=0;j<i;j++){
				z = 1;
				for(k=j;k<n;k+=i){
					if(!a[k]){
						z = 0;
						break;
					}
				}
				if(z){
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}

