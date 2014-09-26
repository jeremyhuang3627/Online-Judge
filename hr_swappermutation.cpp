#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

int n,k;

int com(int n,int r){
	int ret = 1;
	int ret2 = 1;
	for(int i=0;i<r;i++){
		ret = (ret * (n-i))%MOD;
		ret2 = (ret2 * (r-i))%MOD;
	}
	return ret/ret2;
}

int s2(int n,int k){
	if(k>=2) return 2*com(n,2);
	else return k*com(n,2) + 1;
}

int s1(int n,int k){
	bool isEven = (k%2==0);
	int ret = 1;
	while(k){
		for(int i=1;i<=k;i++){
			ret = (ret * (n-i))%MOD;
		}
		k-=2;
	}
	if(isEven) ret = (ret + 1)%MOD; 
	return ret;
}

int main() {
   	cin >> n >> k;
   	cout << s1(n,k) << " " << s2(n,k) << endl; 
    return 0; 
}