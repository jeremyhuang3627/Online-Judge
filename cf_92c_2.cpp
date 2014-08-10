#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define MAX 1000005

using namespace std;

char a [MAX];
char b [MAX];
int next[MAX][26];

int main(){
	int n,t,M,N,i,j,k,ans = 1;
	scanf("%s%s",a,b); N = strlen(a), M = strlen(b);
	for(i='a';i<='z';i++) for(j=N-1,t=N;j>=0;j--){
		if(a[j]==i) t = j;
		next[j][i-'a'] = t; 
	}
	for(i=0,t=0;i<M;i++){
		k = b[i] - 'a';
		if(next[0][k]==N) break;
		if(t==N || next[t][k] == N) t=0,ans++;
		t = next[t][k];t++;
	}
	printf("%d\n",i<M?-1:ans);
}