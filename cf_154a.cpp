#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int n,x,y,cnt=0;
string s,f;

int main(){
	cin >> s >> n;
	F(i,0,n){
		cin >> f;
		x = y = 0;
		F(j,0,s.length() + 1){
			if(s[j] == f[0])x++;
			else if(s[j] == f[1]) y++;
			else{
				cnt += min(x,y);
				x = y = 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}