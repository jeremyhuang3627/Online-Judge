#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define M 10000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int b [12 + 5];

void bin_conv(int i){
	Set(b,0);
	int index = 0;
	while(i){	
		b[index++] = i%2;
		i = i/2; 
	}
	reverse(b,b + sizeof(b)/sizeof(int));
}

int main(){
	while(true){
		int t,n;
		scanf("%d %d",&t,&n);
		if(t == 0 && n == 0){
			break;
		}

		int n_arr [12 + 5];

		map<string,bool> printed;
		string saved [5000];
		int savedCnt = 0;

		F(i,0,n){
			scanf("%d",&n_arr[i]);
		}

		sort(n_arr,n_arr + n);

		int limit = 1 << n;
		bool none = true;
		for(int i=limit-1;i>=1;i--){
			bin_conv(i);
			int sum = 0;
			for(int j=16;j>=(16 - n + 1);j--)
			{
				if(b[j]){
					//cout << "b["<< j <<"]" << endl;
					sum += n_arr[n - ( 16 - j ) - 1 ];
				}
			}

			if(sum==t){
				char token [5];
				string output = "";
				none = false;
				for(int j=16;j>=(16 - n + 1);j--)
				{
					if(b[j]){
						sprintf(token,"%d",n_arr[n - ( 16 - j ) - 1 ]);
						output += token;
						output += "+";
					}
				}
				output = output.substr(0,output.length()-1);
				if(!printed[output]){
					printed[output] = true;
					saved[savedCnt] = output;
					savedCnt++;
				}
			}
		}
		printf("Sums of %d:\n",t);
		if(none){
			printf("NONE\n");
		}else{
			sort(saved,saved + savedCnt);
			for(int i=savedCnt-1;i>=0;i--){
				cout << saved[i] << endl;
			}
		}
	}
	return 0;
}

