#include <iostream>
#include <cstdio>
#include <algorithm>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d\n",n + m - 1);
	if(n >= m){

		F(i,0,n){
			cout << i + 1 << " 1" << endl;
		}

		F(i,1,m){
			cout << "1 " << i + 1 << endl;
		}

	}else{

		F(i,0,m){
			cout << "1 " << i + 1 << endl;
		}


		F(i,1,n){
			cout << i + 1 << " 1"<< endl;
		}
	}

	return 0;
}