#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b)  (a > b ? a : b)

using namespace std;

char c [500000 + 5];
int n,k;

bool change(int i){
	bool changed = false;
	char color;
	F(j,0,k){
		color = 65 + j;
		if(i == 0 && color != c[i+1]){	
			c[i] = color;
			changed = true;
		}else if(color != c[i-1] && color != c[i+1])
		{
			c[i] = color;
			changed = true;
		}
	}
	return changed;
}

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",c);
	int i=0;
	int cnt = 0;
	while(c[i+1] !='\0'){
		if(c[i] == c[i+1]){
			cnt++;
			if(!change(i+1)){
				change(i);
			}
		}
		i++;
	}

	cout << cnt << endl;
	string s = string(c);
	cout << s << endl;

	return 0;
}