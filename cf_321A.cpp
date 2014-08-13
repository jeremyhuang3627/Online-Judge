#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a,b,x[105],y[105],c,d;
string s;

int main()
{
	cin >> a >> b >> s;
	for(int i=0;i<s.length();i++){
		c = c + (s[i] == 'R') - (s[i]=='L');
		d = d + (s[i] == 'U') - (s[i]=='D');
		x[i] = c;
		y[i] = d;
	}

	for(int i=0;i<s.length();i++){

		int h_d = a - x[i];
		int v_d = b - y[i];
		int h_r = c?h_d%c:0;
		int v_r = d?v_r%d:0;
		int h = c?h_d/c:0;
		int v = d?v_d/d:0;

		if(v_r==0 && h_r == 0 && (v==h || (c==0 && h_d==0) || (d==0 && v_d == 0))){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}