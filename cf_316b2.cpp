#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )

using namespace std;

int a [1001];
int visited[1001];
int positions [1001];
map<int,int> ans;

int main(){
	int j,n,x,pos,p,cnt,tail,head,x_head;
	fill_n(visited,1001,0);
	fill_n(positions,1001,0);
	scanf("%d%d",&n,&x);
	F(i,1,n + 1){
		scanf("%d",&a[i]);
	}

	F(i,1,n + 1){
		if(!visited[i]){
			p = i; cnt = 0; tail = 0;
			while(p!=0){
				visited[p] = true; cnt ++;
				head = p; p = a[p];
				if(p==x){
					tail = 1;
					break;
				}
			}
			if(x==i){
				pos = cnt;
				x_head = head;
			}

			if(!tail){
				ans[head] = cnt;
			}
		}
	}

	map<int,int>::iterator it;
	
	vector<int> out;
	F(i,0,1<<ans.size()){
		int sum = pos;
		for(it=ans.begin(),j = 0;it!=ans.end();it++,j++){
			if(i>>j & 1 && it->first != x_head){
				sum += it->second;
			}
		}
		if(!positions[sum]){
			positions[sum] = 1;
			out.push_back(sum);
		}
	}

	sort(out.begin(),out.end());

	F(i,0,out.size()){
		printf("%d\n",out[i]);
	}

	return 0;
}