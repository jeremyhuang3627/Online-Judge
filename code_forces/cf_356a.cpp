#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define F(i,a,n) for(int i=a;i<n;i++)

int main(){
	int n,m,l,r,x;	
	scanf("%d%d",&n,&m);
	set<int> s;
	int ans [n + 1];
	fill_n(ans,n+1,0);
	F(i,0,n){
		s.insert(i + 1);
	}

	F(i,0,m){
		scanf("%d%d%d",&l,&r,&x);
		//cout << "l " << l << " r " << r << " x " << x << endl;
		set<int>::iterator it = s.lower_bound(l);
		while(it != s.end()){
			int cur = *it;
			if(cur > r){
				break;
			}else if(cur >= l && cur != x){
				ans[cur] = x;
				//cout << "cur " << cur << " ans " << x << endl;
				s.erase(cur);
			}
			it++;
		}
	}

	F(i,1,n+1){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}