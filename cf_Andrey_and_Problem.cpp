#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>


using namespace std;

int main(){
	int n,i,j;
	double p[200],g=1,q=0,prob;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lf",&p[i]);
	sort(p,p+n);

	for(int i=n-1;i>=0 && q < g;i--){
		q = q * (1-p[i]) + g * p[i];
		g *= (1-p[i]);
	}

	printf("%.12f\n",q);
	return 0;
}