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

int b [20 + 5];

void bin_conv(int i){
	Set(b,0);
	int index = 0;
	while(i){
		b[index++] = i%2;
		i = i/2;
	}
	reverse(b,b + sizeof(b)/sizeof(int));
}

void print(int * arr,int n)
{
	printf("---print---\n");
	F(i,0,n){
		printf("%d",arr[i]);
	}
	printf("\n-----end------\n");
}

int main(){
	int cn;
	scanf("%d",&cn);
	F(i,0,cn){
		int n;
		scanf("%d",&n);
		int n_arr [20 + 5];
		int c_arr [20 + 5];
 		Set(c_arr,0);
		int totalVotes = 0;

		F(j,0,n)
		{
			scanf("%d",&n_arr[j]);
			totalVotes += n_arr[j];
		}

		int limit = 1 << n;
		for(int j=limit-2;j>=1;j--)
		{
			bin_conv(j);
			int coalVotes = 0;
			for(int k=24;k>=(24 - n + 1);k--)
			{
				if(b[k]){
					//cout << "n_arr["<< k - 26 + n - 1  <<"] " << n_arr[k - 26 + n - 1] << endl;
					coalVotes += n_arr[k - 24 + n - 1];
				}
			}

			if(coalVotes <= totalVotes/2){
				for(int k=24;k>=(24 - n + 1);k--)
				{
					int index = k - 24 + n - 1;
					//cout << "index " << index << " k  "<< k << endl;
					if(!b[k] && (coalVotes + n_arr[index]) > totalVotes/2){
						c_arr[index]++;
					}
				}
			}
		}

		F(j,0,n){
			printf("party %d has power index %d\n",j+1, c_arr[j]);
		}
		printf("\n");
	}

	return 0;
}