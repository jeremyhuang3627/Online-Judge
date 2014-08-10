#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1000005

using namespace std;

char c1 [1000005];
char c2 [1000005];

int main(){
	scanf("%s",c1);
	scanf("%s",c2);

	string s1 (c1);
	string s2 (c2);

	int j = s2.length() - 1;
	int i = s1.length()-1;
	int cnt = 1;
	bool hasAns = false;
	while(j>=0){
		while(true){
			if(s1[i]==s2[j]){
				i--;
				hasAns = true;
				break;
			}
			i--;

			if(i<0 && hasAns){
				i = s1.length()-1;
				hasAns = false;
				cnt++;
			}else if(i<0){
				cout << -1 << endl;
				return 0;
			}
		}
		j --;
	}

	cout << cnt << endl;
	return 0;
}