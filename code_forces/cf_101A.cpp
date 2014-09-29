#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 100005

string s;
int k,i,cnt,b[M],ans;
pair<int,int> a[26];

int main()
{
	cin >> s >> k;
	for(i=0;i<s.length();i++){
		if(a[s[i]-'a'].first == 0) cnt++;
		a[s[i]-'a'].first++;
		a[s[i]-'a'].second = s[i]-'a';
	}
	sort(a,a+26);
	for(i=0;i<26;i++){
		if(a[i].first){
			k -= a[i].first;
			ans++;
			if(k<0) break;
			b[a[i].second] = true;
		}
	}
	cout << ( k < 0 ? cnt-ans+1 : cnt - ans) << endl;
	for(i=0;i<s.length();i++){
		if(b[s[i]-'a']==0) cout << s[i];
	}
	cout << endl;
	return 0;
}