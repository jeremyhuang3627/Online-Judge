#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int a [500 + 10];

int main(){
	int n;

	map<int,bool> m;
	F(i,1,101){
		int tri = (i+1)*i/2;
		m[tri] = true;
	}

	scanf("%d",&n);

	if(!m[n]){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}

	return 0;
}