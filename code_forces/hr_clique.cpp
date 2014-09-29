#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T,N,M,r;

double turan(double n,double r){
	return (1-1/r)*n*n/2;
}

int main()
{
	cin >> T;
	while(T--){
		cin >> N >> M;
		bool ok = false;
		for(r=2;r<N;r++)
		{
			if(turan((double)N,(double)r) >= M){
				break;
			} 
		}
		cout << r << endl;
	}
	return 0;
}