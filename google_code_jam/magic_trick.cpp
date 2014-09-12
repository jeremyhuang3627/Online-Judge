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

int T,r1,r2,m1[5][5],m2[5][5];

vector<int> check()
{
	vector<int> v;
	for(int i=0;i<4;i++)for(int j=0;j<4;j++){
		if(m1[r1-1][i] == m2[r2-1][j]){
			v.push_back(m2[r2-1][j]);
			break;
		}
	}
	return v;
}

int main()
{
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		cin >> r1;
		for(int j=0;j<4;j++)for(int k=0;k<4;k++){
			cin >> m1[j][k];
		}
		cin >> r2;
		for(int j=0;j<4;j++)for(int k=0;k<4;k++){
			cin >> m2[j][k];
		}

		vector<int> ans = check();
		cout << "Case #" << i << ": ";
		if(ans.size() > 1){
			cout << "Bad magician!" << endl;
		}else if(ans.size() == 1){
			cout << ans[0] << endl;
		}else{
			cout << "Volunteer cheated!" << endl;
		}
	}
	return 0;
}