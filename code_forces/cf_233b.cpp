#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath> 

using namespace std;

#define F(i,a,n) for(int i=a;i<n;i++)
#define ULL unsigned long long
#define LL long long
#define max(a,b) (a > b ? a : b )


int s(LL x){
	int sum = 0;
	LL l = x;
	while(l != 0){
		sum += l%10;
		l = l/10;
	}
	return sum;
}

int main(){
	long double n;
	cin >> n;
	LL nsqrt = (LL)ceil(sqrt(n));
	//cout << "nsqrt " << nsqrt << endl;
	for(LL i = max(nsqrt - 90,0);i<nsqrt;i++){
		LL ans = i*i + s(i) * i;
		//cout << "i " << i << " ans " << ans << endl;
		if(ans == n){
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1" << endl;

	return 0;
}