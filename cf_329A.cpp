#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define M 105

using namespace std;

int n,row_ok,col_ok,r[M],c[M];
char g[M][M];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",g[i] + 1);
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j] == '.'){
				r[i] = j;
				c[j] = i;
			}
		}
	}

	row_ok = col_ok = 1;
	for(int i=1;i<=n;i++){
		if(!r[i]) row_ok = 0;
		if(!c[i]) col_ok = 0;
	}

	if(!row_ok && !col_ok){
		cout << "-1" << endl;
	}else{
		for(int i=1;i<=n;i++){
			if(row_ok) cout << i << " " << r[i] << endl;
			else if(col_ok) cout << c[i] << " " << i << endl;
		}
	}
	
	return 0;
}