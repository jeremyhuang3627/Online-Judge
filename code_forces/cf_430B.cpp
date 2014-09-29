#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <string>

using namespace std;

#define M 105

int n,k,x,a[M]; 

int check(int i)
{
	int c = x,p1=i,p2=i+1;
	bool insert = true;
	int sum = 0,cnt;
	while(true)
	{
		cnt = 0;
		while(p1>=0 && a[p1]==c){
			p1--;
			cnt++;
		}
		while(p2<n && a[p2]==c){
			p2++;
			cnt++;
		}
		//cout << "count for c " << c << " cnt " << cnt << endl;
		if(cnt >= 2 && insert){
			sum+=cnt;
			insert = false;
		}else if(cnt>=3){
			sum+=cnt;
		}else{
			break;
		}

		if( (p1 < 0 && p2 >= n )|| (a[p1] != a[p2])) break;
		else c = a[p1];
	}
	return sum;
}

int main()
{
	cin >> n >> k >> x;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		//cout << "check(" << i << ") "<< check(i) << endl;
		ans = max(ans,check(i));
	}
	cout << ans << endl;
	return 0;
}