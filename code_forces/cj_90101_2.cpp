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
	vector<vector<char> > v (L);
	bool inBracket = false;
	int pos = 0;
	//cout << "s " << s << endl;
	for(int i=0;i<s.length();i++)
	{
		//cout << "i " << i << endl;
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
		for(int j=0;j<m[i].size();j++)
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

	for(int i=0;i<D;i++)
	{
		cin >> s;
		dict.push_back(s);
	}

	for(int i=1;i<=N;i++)
	{
		cin >> s;
		int sum = 0;

		vector<vector<char> > m = convert(s);
		for(int i=0;i<D;i++)
		{
			if(check(dict[i],m))sum++;
		}
		cout << "Case #"<< i << ": " << sum << endl;
	}

	return 0;
}