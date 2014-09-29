#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n,m,r;

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;)
	{
		for(int j=1;j<=m;j++,i++)
		{
			if(i>n) break;

			if(m%2==1){
				if(j%2==0) cout << (m+1)/2 - (j/2) << endl;
				else cout << (m+1)/2 + (j/2) << endl;
			}else{
				if(j%2==1) cout << (m+1)/2 - (j/2) << endl;
				else cout << (m+1)/2 + (j/2) << endl;
			}
		}
	}

	return 0;
}