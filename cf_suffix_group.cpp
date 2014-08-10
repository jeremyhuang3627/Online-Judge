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

string s [100000 + 5];

int findMax(int start,int end,int pos){
	//cout << "s " << start << " e " << end << " pos " << pos << endl;
	if(start == end){
		return 1;
	}

	int totalCnt = 0;
	char cur;
	int curIdx = -1;
	int maxCnt = 0;
	int i = start;
	while(i<=end){
		if(s[i][pos] == '\0'){
			totalCnt ++;
		}else{
			cur = s[i][pos];
			curIdx = i;
			while(s[i][pos] == cur && i<=end){
				i++;
			}
			i--;
			maxCnt = max(findMax(curIdx,i,pos + 1),maxCnt);
		}
		i++;
	}
	return totalCnt + maxCnt;
}

int main(){
	int ln;
	scanf("%d",&ln);
	int maxLen = 0;
	F(i,0,ln){
		char str [100000 + 5];
		scanf("%s",str);
		s[i] = string(str);
		maxLen = max(maxLen,s[i].length());
	}
	sort(s,s + ln);
	//cout << "maxLen " << maxLen << endl;
	int maxSize = findMax(0,ln-1,0);
	cout << maxSize << endl;

	return 0;
}