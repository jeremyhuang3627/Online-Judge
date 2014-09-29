#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int w,m,k,i=0;

int main()
{
	cin >> w >> m >> k;
	while(true){
		w-=f(m + i)*k;
		if(w<0)break;
		i++;
	}
	cout << i << end;
	return 0;
}