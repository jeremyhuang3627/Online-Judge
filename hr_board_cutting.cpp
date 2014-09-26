#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long T,M,N,x,y,v[1000005],h[1000005];

bool cmp(int a,int b){
	return a > b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	cin >> T;
	while(T--)
	{
		cin >> M >> N;
		for(int i=0;i<M-1;i++) cin >> v[i];
		for(int i=0;i<N-1;i++) cin >> h[i];
		sort(v,v+M-1,cmp);
		sort(h,h+N-1,cmp);

		int sum=0,i=0,j=0,vs=1,hs=1;
		while(i<M-1 && j<N-1){
		//	printf("v[%d] %d\n",i,v[i]);
		//	printf("h[%d] %d\n",j,h[j]);
			if(v[i] > h[j]){
				sum = (sum + ((j+1)*v[i])%MOD)%MOD;
				//printf("hs %d v[%d] %d %d\n",hs,i,v[i],hs*v[i]);
				i++;
			}else{
				sum = (sum + ((i+1)*h[j])%MOD)%MOD;
				//printf("vs %d h[%d] %d %d\n",vs,j,h[j],vs*h[j]);
				j++;
			}
		}

		while(i<M-1){
			sum = (sum + ((j+1)*v[i])%MOD)%MOD;
		//	printf("hs %d v[%d] %d %d\n",hs,i,v[i],hs*v[i]);
			i++;
		}

		while(j<N-1){
			sum = (sum + ((i+1)*h[j])%MOD)%MOD;
			j++;
		}

		cout << sum << endl;
	}
    return 0;
}
