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

int L,D,N; 
vector<string> dict;
string s;

vector<vector<char> > convert(string s)
{
	vector<vector<char> > v;
	bool inBracket = false;
	int pos = 0;
	for(int i=0;i<s.length();i++)
	{
		if(!inBracket){
			if(s[i] == '('){
				inBracket = true;
			}else{
				v[pos].push_back(s[i]);
				pos++;
			}
		}else{
			if(s[i]==')'){
				inBracket = false;
				pos++;
			}else{
				v[pos].push_back(s[i]);
			}
		}
	}
	return v;
}

bool check(string ss,vector<vector<char> > &m)
{
	for(int i=0;i<ss.length();i++)
	{
		bool ok = false;
		for(int j=0;j<m[i].length();j++)
		{
			if(m[i][j]==ss[i]){
				ok = true;
				break;
			}
		}
		if(!ok){
			return false; 
		}
	}
	return true;
}

int main()
{
	cin >> L >> D >> N;

	dict.resize(L);

	while(D--)
	{
		cin >> s;
		dict.push_back(s);
	}

	while(N--)
	{
		cin >> s;
		int sum = 0;
		vector<vector<char> > m = convert(s);
		for(int i=0;i<N;i++)
		{
			if(check(dict[i],m))sum++;
		}
		cout << sum << endl;
	}

	return 0;
}