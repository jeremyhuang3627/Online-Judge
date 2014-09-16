#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <string>
#include <stack>

using namespace std;

string s;

int main()
{
	cin >> s;
	stack<char> st;
	int cnt;
	for(int i=0;i<s.length();i++)
	{
		if(st.size() >0 && st.top() == '(' && s[i] == ')'){
			cnt+=2;
			st.pop();
		}else{
			st.push(s[i]);
		}
	}
	cout << cnt << endl;
	return 0;
}