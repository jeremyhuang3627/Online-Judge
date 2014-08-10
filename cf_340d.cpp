#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b)  (a > b ? a : b)

using namespace std;

int a [100000 + 1];

int bin_search(int *s,int s_len,int val)
{
	int lo = 0;
	int hi = s_len - 1;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(a[s[mid]] > val){
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
	int n;

	scanf("%d",&n);

	F(i,0,n){
		scanf("%d",&a[i]);
	}

	int s [100000 + 1];
	int s_len = 0;
	int p [100000 + 1];
	p[0] = -1;
	F(i,0,n){
		if(s_len == 0){
			s[s_len] = i;
			s_len ++;
		}else{
			int j;
			if(a[i] > a[s[s_len - 1]]){
				s[s_len] = i;
				p[i] = s[s_len - 1];
				s_len ++;
			}else{
				j = bin_search(s,s_len,a[i]);
				s[j] = i;
				p[i] = s[j-1];
			}
		}
	}

	printf("%d\n",s_len);
	return 0;
}