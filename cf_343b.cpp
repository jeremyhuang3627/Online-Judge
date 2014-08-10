#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define F(i,a,n) for(int i=a;i<n;i++)

int main(){
	char c [100000 + 100];
	scanf("%s",c);
	vector<char> v;
	int i=0;
	while(c[i]!='\0'){
		v.push_back(c[i]);
		if(v.size() >=2 && v[v.size() - 1] == v[v.size()-2]){
			v.pop_back();
			v.pop_back();
		}
		i++;
	}

	if(v.size()){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}

	return 0;
}