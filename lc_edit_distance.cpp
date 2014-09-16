#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 1000001

int look[M][M];

int longComSub(string &s1,string &s2,int i,int j)
{	
//	cout << "i " << i << " j " << j << endl;
	if(i < 0 || j < 0){
		return 0;
	}else if(look[i][j]!=0){
		return look[i][j];
	}else{
		if(s1[i]==s2[j]){
			look[i][j] = longComSub(s1,s2,i-1,j-1) + 1;
		}else{
			look[i][j] = max(longComSub(s1,s2,i-1,j),longComSub(s1,s2,i,j-1));
		}
		return look[i][j];
	}
}

int minDistance(string word1, string word2) {
	memset(look,0,sizeof(look[0][0]));
    int mm = longComSub(word1,word2,word1.length()-1,word2.length()-1);
    return word2.length()-mm;
}

int main()
{
	string s1 = "";
	string s2 = "";
//	cout << "t2 " << endl;
	int ans = minDistance(s1,s2);	 
	cout << ans << endl;
	return 0;
}