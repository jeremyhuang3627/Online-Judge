#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int dp[100000][100000];

int longestValidParentheses(string s) {
		if(s.length()<=1){
			return 0;
		}

	   	for(int i=0;i<s.length();i++)
	   	{
	   		for(int j=i;j>=0;j--)
	   		{	
	   			if(i-j==0){
	   				dp[j][i] = 0;
	   			}else if(i-j==1){
	   				dp[j][i] = (s[i] == ')' && s[j] == '(');
	   			}else{
		   			int c1 = (s[j] == '(' && s[j+1] == ')') ? dp[j+2][i] + 1 : dp[j+1][i];
		   			int c2 = (s[i-1] == '(' && s[i] == ')') ? dp[j][i-2] + 1 : dp[j][i-1];
		   			int c3 = ((s[i] == ')' && s[j] == '(') ? dp[j+1][i-1] + 1 : 0);
		   			dp[j][i] = max(c1,max(c2,c3));
		   		}
	   		}
	   	}
	   	return dp[0][s.length()-1]*2;
}

int main()
{
	string s = "";
	int ans = longestValidParentheses(s);
	cout << "ans for " << s << " is " << ans << endl;
	return 0;
}