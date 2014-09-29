#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
	int n;

	string s = "ROYGBIV";

	scanf("%d",&n);

	string out = "";

	F(i,0,n){
		out += s[i%s.length()];
	}

	//cout << "out before swap " << out << endl;

	int rmd = n % 7;

	if(rmd<4){
		F(i,0,rmd){
			char temp = out[out.length() - i - 1];
			out[out.length() - i - 1] = out[out.length() - i - 4];
			out[out.length() - i - 4] = temp;
		}
	}

	cout << out << endl;
	return 0;
}