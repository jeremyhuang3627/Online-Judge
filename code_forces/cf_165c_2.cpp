#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1005
#define MX 1000005

using namespace std;

long long a[1<<20],k,i,j,q,o=1,t;
string s;

int main(){
	cin >> k >> s;
	for(q=s.size();i<q;) if(s[i++]-48) a[o++] = i;
	a[o] = q + 1;
	for(i=k;i<o;) t += (a[i+1]-a[i++])*(a[j+1] - a[j++] - !k)/(1+!k);
	cout << t << endl;
	return 0;
}