#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int n,sz,amt,k,tbsz;
int grpsz [1001];
int spend [1001];
vector<pair<int,int> > tb;
int used[1001] = {0};

int main(){
	scanf("%d",&n);

	F(i,0,n){
	    scanf("%d%d",&grpsz[i],&spend[i]);
	}

	scanf("%d",&k);

	F(i,0,k){
		scanf("%d",&tbsz);
		tb.push_back(make_pair(tbsz,i));
	}	

	sort(tb.begin(),tb.end());

	int total = 0;
	vector<pair<int,int> > p;
	F(i,0,k){
		int mx = 0;
		int idx = -1;
		F(j,0,n){
			if(grpsz[j] <= tb[i].first && spend[j] > mx && !used[j]){
				mx = spend[j];
				idx = j;
			}
		}
		if(idx != -1){
			total += mx;
			used[idx] = 1;
			p.push_back(make_pair(idx,tb[i].second));
		}
	}

	cout << p.size() << " " << total << endl;

	F(i,0,p.size()){
		cout << p[i].first + 1 << " " << p[i].second + 1 << endl;
	}
	
	return 0;
}