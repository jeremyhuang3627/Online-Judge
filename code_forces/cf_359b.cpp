#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int n,k;
int a [50005*2];

void swap(int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,2*n+1){
		a[i] = i;
	}
	F(i,1,k+1){
		swap(2*i,2*i-1);
	}
	F(i,1,2*n+1){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}