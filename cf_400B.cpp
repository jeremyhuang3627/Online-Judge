#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define M 1005

using namespace std;

int n,m,d[M],g,s,ans=0;
char a[M][M];

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
		for(int j=0;j<m;j++){
			if(a[i][j] == 'G'){
				g = j;
			}

			if(a[i][j] == 'S'){
				s = j;
			}
		}

		if(s-g < 0){
			cout << "-1" << endl;
			return 0;
		}
		d[s-g]++;
	}

	for(int i=0;i<m;i++){
		if(d[i]){
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}