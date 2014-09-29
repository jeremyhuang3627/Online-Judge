#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int T,N,a[51],h[51];

int p(int n,int m){
	if(m > n) return 0;
	else{
		int ret = 1;
		while(m > 0){
			ret *= n--;
			m--;
		}
		return ret;
	}
}

int main()
{
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0;i<N;i++) cin >> a[i];
		sort(a,a+N);
		for(int i=1;i<N;i++){
			if(a[i] > a[i-1]) h[i] = i; 
			else h[i] = h[i-1];
			//cout << "h["<< i <<"] " << h[i] << endl;
		}
		double tt = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				double ret2 = 1;
				if(h[j] < i) ret2 = 0;
				for(int l=0;l<i;l++){
						ret2 *= (double)(h[j]-l)/(N-l);
				}
				ret2 /= (N-i);
				tt += ret2*(i+1);
				for(int k=0;k<i;k++){
					if(h[j] < k) continue;
					double ret = 1;
					for(int l=0;l<k;l++){
						ret *= (double)(h[j]-l)/(N-l);
					}
					ret /= (N-k);
					ret /= (N-k-1);
					tt += ret * (N-h[j]-1) * (k+1);
				//	tt+= ((double)p(h[j],k)*(N-h[j]-1)/p(N,k+2))*(k+1);
				/*	cout << "add " << ((double)p(h[j],k)*(N-h[j]-1)/p(N,k+2))*(k+1) << endl;
					cout << "p(h[j],k) " << p(h[j],k) << endl;
					cout << "(N-h[j]-1) " << (N-h[j]-1) << endl;
					cout << "p(N,k+2) " << p(N,k+2) << endl; */
				}
			//	cout << "tt " << tt << endl;
			}
		}
		printf("%.2f\n",tt);
	}
	return 0;
}