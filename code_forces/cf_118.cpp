#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define mod 100000000

using namespace std;

int z[101][101][3];

int main(){
	int n1,n2,k1,k2;
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	memset(z,0,sizeof(z));
	z[0][0][1] = z[0][0][2] = 0;

	F(i,1,n1 + 1){
		if(i<=k1){
			z[i][0][1] = 1;
		}else{
			z[i][0][1] = 0;
		}
		z[i][0][2] = 0;
	}

	F(i,1,n2 + 1){
		if(i<=k2){
			z[0][i][2] = 1;
		}else{
			z[0][i][2] = 0;
		}
		z[0][i][1] = 0;
	}

	F(i,1,n1 + 1){
		F(j,1,n2 + 1){
			F(k,1,min(k1,i) + 1){
				z[i][j][1] = (z[i][j][1] + z[i-k][j][2])%mod;
			} 
			F(k,1,min(k2,j) + 1){
				z[i][j][2] = (z[i][j][2] + z[i][j-k][1])%mod;
			}
		}
	}

	cout << (z[n1][n2][1] + z[n1][n2][2])%mod << endl;

	return 0;
}