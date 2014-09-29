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
#define ULL unsigned long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
//#define maxInt = numeric_limits<int>::max();

using namespace std;

int main(){
	int n;
	vector<int> in;
	vector<int> in_sorted;
	int cnt = 0;
	while(scanf("%d",&n) != EOF){
		//cout << "n " << n << endl;
		in.push_back(n);
		in_sorted.push_back(n);
		cnt ++;
	}

	int t [cnt + 1][cnt + 1];
	pair<int,int> d [cnt + 1][cnt + 1];

	sort(in_sorted.begin(),in_sorted.end());

	F(i,0,in.size() + 1){
		F(j,0,in_sorted.size() + 1){
			if(i==0 || j==0){
				t[i][j] = 0;
			}else{
				if(in[i-1] == in_sorted[j-1]){
					t[i][j] = t[i-1][j-1] + 1;
					d[i][j] = make_pair(i-1,j-1);
				}else{
					if(t[i-1][j] > t[i][j-1]){
						t[i][j] = t[i-1][j];
						d[i][j] = make_pair(i-1,j);
					}else{
						t[i][j] = t[i][j-1];
						d[i][j] = make_pair(i,j-1);
					}
				}
			}
		}
	}

	int i = cnt;
	int j = cnt;

	map<int,bool> repeat;
	vector<int> arr;
	while(i>0 && j>0)
	{	
		pair<int,int> p = d[i][j];
		if(i - p.first  == 1 && j - p.second == 1){
			if(!repeat[in[i-1]]){
				repeat[in[i-1]] = true;
				arr.push_back(i-1);
				//cout << "pushing " << in[i-1] << endl;
			}
		} 

		
		i = p.first;
		j = p.second;
	}

	cout << arr.size() << endl;
	cout << "-" << endl;
	for(int i=arr.size()-1;i>=0;i--)
	{
		cout << in[arr[i]] << endl;
	}
	return 0;
}

