#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define M 1000005
#define max(a,b) ((a > b) ? a : b)

int T,N,p,q,r,s,a[M];
long long sum=0,b[M];
double m=0;

int main()
{
	cin >> T;
	for(int k=1;k<=T;k++){
		cin >> N >> p >> q >> r >> s;
		cout << "N " << N << " p " << p << " q " << q << " r " << r << " s " << s << endl;
		for(int i=0;i<N;i++)
		{
			a[i] = (i*p+q)%r + s;
			sum += a[i];
			b[i] = sum;
		}
		for(int i=0;i<N;i++) for(int j=i;j<N;j++){
			long long mid = (i ? b[j] - b[i-1] : b[j]);
			long long front = (i ? b[i-1] : 0);
			long long back = sum - mid - front;
			long long largest = max(mid,max(front,back));
			cout << "largest " << largest << endl;
			m = max(1-(long double)largest/sum,m);
		}
		printf("Case #%d: %.9f\n",k,m);
	}
	return 0;
}