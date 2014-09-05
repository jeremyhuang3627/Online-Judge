#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 200000

int c=0,n;
char s[M];

int main()
{	
	scanf("%s",s);
	n = strlen(s);
	char prev_char = s[0];
	int two_cnts = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i]==prev_char){
			c++;
		}else{
			c=0;
			prev_char = s[i];
		}

		if(c>=2){
			s[i] = '.';
		}
	}

	prev_char = s[0];
	c = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i] != '.'){
			if(s[i]==prev_char){
				c++;
			}else{
				if(!c) two_cnts = 0;
				c=0;
				prev_char = s[i];
			}

			if(c==1 && two_cnts == 0){
				two_cnts ++;
			}else if(c==1){
				two_cnts = 0;
				s[i] = '.';
			}
		}
	}

	for(int i=0;i<n;i++){
		if(s[i]!='.'){
			cout << s[i];
		} 
	}
	cout << endl;

	return 0;
}