#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int main(){
	char s1 [2005];
	char s2 [2005];
	scanf("%s",s1);
	scanf("%s",s2);
	string str1 (s1);
	string str2 (s2);


	int maxLen = 0;
	F(i, -1 * (int)(str2.length()-1),(int)str1.length()){
		int cnt = 0;
		F(j,0,str2.length()){
			if(j+i>=0 && j + i <str1.length()){
				if(str1[j+i] == str2[j]){
					cnt++;
				}
			}
		}
		//cout << "cnt " << cnt << endl;
		maxLen = max(maxLen,cnt);
	}
	//cout << "maxLen " << maxLen << endl;
	cout << str2.length() - maxLen << endl;
	return 0;
}