//Easy Problem from Rujia Liu?
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
	while(true){
		int len, qs;
		cin >> len >> qs;
		if(cin.eof()){
			break;
		}
		vector<int> v; 
		map<int,vector<int> > m;
		for(int i=0;i<len;i++)
		{	
			int num;
			cin >> num;
			m[num].push_back(i);
			v.push_back(num);
		}

		for(int i=0;i<qs;i++){
			int k,v;
			cin >> k >> v;
			if(k <= m[v].size()){
				cout << m[v][k-1] + 1 << endl;
			}else{
				cout << 0 << endl;
			}
		}
	}
	return 0;
}

