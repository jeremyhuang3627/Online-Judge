#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <string>

using namespace std;

int T;
double C,F,X;

int main()
{
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cin >> C >> F >> X;
		double tt = 0,r=2.0;
		int j=0;
		double nt = (tt + X/(r + F));
		while(tt<=X)
		{
			//if((tt + X/(r + F)) < (tt+C/r) )
			if( tt + X/r <= tt + C/r + X/(r+F)){
				printf("Case #%d: %.7f\n",i,tt+X/r);
			//	cout << "Case #" << i << ": " << tt + X/r << endl;
				break;
			}
			tt += C/r, r += F; 
		}
	}
	return 0; 
}