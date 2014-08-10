#include <stdio.h>
#include <string.h>
#include <iostream>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1000005

using namespace std;

int p[M],k,n;
bool a[M];
char s[M + 1];

int main()
{
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i=2;i<=n;i++){
		for(k=p[i-1];k>0 && s[k+1] != s[i];k=p[k]);
	p[i] = k + int(s[k+1] == s[i]);
	}

	for(int i=2;i<n;i++) a[p[i]] = true;
	for(k=p[n];k>0;k=p[k]){
		if(a[k]) break;
	}
	if(k==0) cout << "Just a legend";
	else{
		for(int i=1;i<=k;i++){
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}