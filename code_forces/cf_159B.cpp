#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define M 100005
#define max(a,b) ((a > b) ? a : b)

using namespace std;

int n,m,i,d,c,bclosed_cnt=0,closed_cnt=0;

vector<int> mark[M];
vector<int> cap[M];

int main()
{
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> c >> d;
		mark[d].push_back(c);
	}

	for(i=0;i<m;i++){
		cin >> c >> d;
		cap[d].push_back(c);
	}

	for(i=0;i<M;i++){
		if(mark[i].size() && cap[i].size()){
			sort(mark[i].begin(),mark[i].end());
			sort(cap[i].begin(),cap[i].end());
			int t_m,t_c;
			t_m = t_c = 0;

			while(t_m < mark[i].size() && t_c < cap[i].size())
			{
				if(mark[i][t_m] < cap[i][t_c]){
					t_m ++;
				}else if(mark[i][t_m] > cap[i][t_c]){
					t_c ++;
				}else{
					t_m++;
					t_c++;
					bclosed_cnt++;
				}
			}
			closed_cnt += min(mark[i].size(),cap[i].size());
		}
	}

	cout << closed_cnt << " " << bclosed_cnt << endl;

	return 0;
}