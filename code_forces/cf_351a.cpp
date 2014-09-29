#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b) (a > b ? a : b)

using namespace std;

double Abs(double x){return (x < 0 ? -x : x);}

int main(){
	int n;
	scanf("%d",&n);
	double ans = 1e9;
	double b;
	int cnt = 0;
	double s = 0.000;
	
	F(i,0,2*n){
		scanf("%lf",&b);
		b-=(int)b;
		s+= b;
		if(b > 0.0001) cnt++;
	}

	for(int i = max(0,cnt-n);i<=min(cnt,n);i++){
		ans = min(ans, Abs(s - i));
	}
	printf("%.3lf\n",ans);
	return 0;
}