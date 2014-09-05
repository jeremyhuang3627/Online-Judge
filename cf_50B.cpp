#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

string s;
long long a[50],sum;

int main()
{
	cin >> s;
	for(int i=0;i<s.length();i++)
	{
		if(isdigit(s[i])){
			a[s[i]-'0' + 26]++;
		}else{
			a[s[i]-'a']++;
		}
	}
	sum = s.length();
	for(int i=0;i<36;i++){
		sum+=a[i]*(a[i]-1);
	}
	cout << sum << endl;

	return 0;
}