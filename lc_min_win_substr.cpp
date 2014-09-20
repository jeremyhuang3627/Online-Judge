#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string minWindow(string S, string T){
	int t[256],c[256],cnt=0,st=0,minLen=S.length(),curLen,ws=0,we=S.length()-1;
	int i =0,j=0;

	for(int i=0;i<T.length();i++){
 		t[T[i++]]++;
	}

	for(int j=0;j<S.length();j++){
		if(t[S[j]]==0) {
			continue;
		}
		if(c[S[j]] < t[S[j]]){
			cnt++;
		}
		c[S[j]]++;
		if(cnt==T.length()){
			while(t[S[st]]==0 || c[S[st]] > t[S[st]]){
				if(c[S[st]] > t[S[st]]) c[S[st]]--;
				st++;
			}
			curLen = j - st + 1;
			if(curLen < minLen){
				ws = st,we = j,minLen = curLen;
			}
		}
	}
	printf("ws %d we %d\n", ws,we);
	return S.substr(ws,we-ws+1);
}

int main()
{
	string s= "abc";
	string t= "b";
	string ans = minWindow(s,t);
	cout << ans << endl;
	return 0;
}