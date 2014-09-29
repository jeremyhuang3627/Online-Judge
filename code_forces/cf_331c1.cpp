#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define ULL unsigned long long
#define M 1000000
using namespace std;

int a [M+100];

int main(){
	int n;
	scanf("%d",&n); a[0] = 0;
	for(int i=1;i<n+1;i++){
		if(i<10){
			a[i] = 1;
		}else{
			int j = i; a[i] = M;
			while(j){
				a[i] = min(a[i],a[i-j%10] + 1); j = j/10;
			}
		}
	}
	printf("%d\n",a[n]);
	return 0;
}