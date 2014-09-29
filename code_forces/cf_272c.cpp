#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define M 100005

long long n,m,w[M],h[M],a[M],i,mm=0,j,e;

int main()
{
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	cin >> m;
	for(i=0;i<m;i++){
		cin >> w[i] >> h[i];
		if(w[i] > e){
			for(j=e;j<w[i];j++){
				if(a[j] > mm){
					mm = a[j];
				}
			}
		}

		cout << mm << endl;
		mm += h[i];
		e = max(w[i],e);
	}
	return 0;
}