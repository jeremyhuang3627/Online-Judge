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
 
using namespace std;

int findTandemLen(string str){
	//cout << "str " << str << endl;
	int len = 0;
	F(i,0,str.length()){
		F(j,i+1,str.length()){
			if(str[i] == str[j]){
				int l = i;
				int m = j;
				int cnt = 0;
				bool isTendem = true;
				while(l < (i + j-i)){
					//cout << str[l] << " " << endl;
					if(str[l] != str[m]){
						isTendem = false;
						break;
					}
					cnt ++;
					l++;
					m++;
				}

				if(isTendem){
					len = max(len,cnt * 2);
					//cout << "len " << len << endl;
				}
			}
		}
	}
	return len;
}

int main(){
	char c [200 + 5];
	int np;
	while(scanf("%s",c)!= EOF){
		string in = string(c);
		scanf("%d",&np);
		int maxLen = np * 2;
		if(in.size() <= np){
			cout << (in.size() + np) / 2 * 2  << endl;
		}else{

			int i = in.size() - np - 1;
			while(i >= 0){
				if( ((in.size() - i) + np) % 2 == 0 ){
					int j = i;

					int n = ( (in.size() - i) + np) / 2;
					bool isTendem = true;
					while(j + n < in.size()){
						if(in[j+n] != in[j]){
							isTendem = false;
							break;
						}
						j++;
					}
					if(isTendem){
						maxLen = max(maxLen,(in.size() - i) + np);
					}
				}	
				i --;
			}

			// find the max tandem len in the string itself
			int str_tandem_len = findTandemLen(in);
			//cout << "str_tandem_len " << str_tandem_len << endl;
			maxLen = max(maxLen,str_tandem_len);

			cout << maxLen << endl;
		}

	}

	return 0;
}