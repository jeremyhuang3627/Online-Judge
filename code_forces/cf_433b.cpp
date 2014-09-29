#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 100005
#define INF 1E9

using namespace std;

long long v[M],v_sum[M],u[M],u_sum[M],n,sum=0,q,t,l,r;

int main(){
	cin >> n;
	F(i,1,n + 1){
		cin >> v[i];
		sum+=v[i];
		v_sum[i] = sum;
		u[i] = v[i];
	}
	sort(u + 1,u + n +1);
	sum = 0;
	F(i,1,n + 1){
		sum += u[i];
		u_sum[i] = sum;
	}
	cin >> q;
	F(i,0,q){
		cin >> t >> l >> r;
		if(t==1){
			cout << v_sum[r] - v_sum[l-1] << endl;
		}else{
			cout << u_sum[r] - u_sum[l-1] << endl;
		}
	}
	return 0;
}