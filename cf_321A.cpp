#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int Z,A,B,V,W,Q,x,y,q,w,X[105],Y[105]; 
string s;

int main()
{
	cin >> A >> B >> s;
	X[Q]=Y[Q]=0;
	Q++;
	for(int i=0;i<s.length();i++){
		V = V + (s[i] == 'R') - (s[i]=='L');
		W = W + (s[i] == 'U') - (s[i]=='D');
		X[Q] = V;
		Y[Q] = W;
		Q++;
	}

	for(int i=0;i<Q;i++){
		q = V?(A-X[i])/V:0, w = W?(B-Y[i])/W:0;
		x = X[i] + q*V,y = Y[i] + w*W;
		if((q==w || V == 0 || W==0) && q>=0 && w >= 0 && x == A && y == B){
			Z = 1;
		}
	}

	cout << (Z?"Yes":"No");
	return 0;
}