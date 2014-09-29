#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

string a,b;


int getOnes(string s)
{	
	int cnt = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == '1'){
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	cin >> a >> b;
	int a_ones = getOnes(a);
	int b_ones = getOnes(b);

	int allowable = a_ones;
	if(a_ones % 2 ==1){
		allowable ++;
	}

	if(allowable >= b_ones ){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}