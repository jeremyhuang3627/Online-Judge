#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define M 100005

using namespace std;

int n,k,a[M],i,sum=0;

int main()
{
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	i=0;
	while(k--){
		a[i] *= -1;i++;
		if(i <= n-1){
			if(a[i] > a[i-1]) i--;
		}else{
			i--;
		}
	}

	for(i=0;i<n;i++){
		sum += a[i];
	}

	cout << sum << endl;
	return 0;
}