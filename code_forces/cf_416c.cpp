#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int n,sz,amt,k;
int tbsz [1001];
int mx [1001];
int pomx [1001];
int used[1001];

int bs(int val,vector<pair<int,int> > &grps)
{
	int lo = 0;
	int hi = grps.size() - 1;

	while(lo <= hi){
		int mid = (hi + lo) / 2;
		if(grps[mid].first < val){
			lo = mid + 1;
		}else if(grps[mid].first > val){
			hi = mid - 1;
		}else{
			return mid;
		}
	}

	return hi;
}

int main(){
	
	scanf("%d",&n);
	vector<pair<int,int> > grps;

	F(i,0,n){
		scanf("%d%d",&sz,&amt);
		grps.push_back(make_pair(sz,amt));
	}

	sort(grps.begin(),grps.end());

	int mxm = grps[0].second;
	int idx = 0;
	F(i,0,n){
		if(grps[i].second > mxm){
			mxm = grps[i].second;
			idx = i;
		}
		mx[i] = mxm;
		pomx[i] = idx;
	}

	scanf("%d",&k);

	F(i,0,k){
		scanf("%d",&tbsz[i]);
	}

	sort(tbsz,tbsz + k);

	int ttamt = 0;

	F(i,0,k){
		int grpnum  = bs(tbsz[k],grps);
		ttamt += mx[grpnum];
	}
	return 0;
}