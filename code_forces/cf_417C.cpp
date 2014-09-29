#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if(2*k >= n){
		printf("-1\n");
	}else{
		printf("%d\n",n*k);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=i+k;j++){
				printf("%d %d\n",i,(j-1)%n+1);
			}
		}
	}
	return 0;
}