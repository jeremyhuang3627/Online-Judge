//code chef Retail Shop
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <tr1/unordered_map>
#include <ctime>
#include <cctype>
#include <cmath>

using namespace std;

bool f[11];

bool isValid(int n,int len){
	int c = 0;
	while(n!=0){
		if(!f[n%10]){
			return false;
		}
		n = n/10;
		c ++;
	}
	if(c!=len){
		return false;
	}
	return true;
}

void solve(){
	int numSol = 0;
	for(int i=111;i<=999;i++)
	{
		for(int j=11;j<=99;j++)
		{
			if(isValid(i,3) && isValid(j,2))
			{
				int pp1 = i * (j%10);
				int pp2 = i * (j/10);
				int pd = i * j;
				if(isValid(pp1,3) && isValid(pp2,3) && isValid(pd,4)) 
				{
					numSol ++;
				}
			}
		}
	}
	cout << numSol << endl;
}

int main(){
	int c,n;
	cin >> c;
	for(int i=0;i<c;i++)
	{
		cin >> n;
		f[n] = true;
	}

	solve();
	return 0;
}