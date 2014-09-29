#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

#define M 100005

int T,N,B[M],dp[M][2];

int main()
{
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0;i<N;i++) cin >>B[i];
		for(int i=0;i<N;i++){
			if(i==0) dp[i][0] = dp[i][1] = 0;
			else{
				dp[i][1] =  max(dp[i-1][1] + abs(B[i]-B[i-1]),dp[i-1][0] + abs(B[i] - 1));
				dp[i][0] =	max(dp[i-1][1] + abs(1-B[i-1]),dp[i-1][0]);
			}
		}
		cout << max(dp[N-1][0],dp[N-1][1]) << endl;
	}
	return 0;
}