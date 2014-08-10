#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b)  (a > b ? a : b)

using namespace std;

int a [15];
int solved = 0;
int solution [1000 + 5];
int cnt;

void solve(int n,int lastUsedIndex,int lw, int rw){
	if(n==0){
		solved = 1;
		return;
	}

	F(i,0,cnt){
		if(i != lastUsedIndex && !solved ){
			if(lw > rw && rw + a[i] > lw){
				solve(n-1,i,lw,rw + a[i]);
				solution[n] = i;
			}else if(lw < rw && rw < lw + a[i]){
				solve(n-1,i,lw + a[i],rw);
				solution[n] = i;
			}else if(lw == 0 && rw == 0){
				solve(n-1,i,lw + a[i],rw);
				solution[n] = i;
			}
		}
	}

}

int main(){
	char c [12];
	int n;
	scanf("%s",c);
	scanf("%d",&n);
	
	int i = 0;
	cnt = 0;
	while(c[i]!='\0'){
		if(c[i] == '1'){
			a[cnt] = i+1;
			cnt ++;
		}
		i++; 
	}

	solve(n,-1,0,0);

	if(solved){
		printf("YES\n");
		for(int i=n;i>0;i--){
			printf("%d ",a[solution[i]]);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}

	return 0;
}