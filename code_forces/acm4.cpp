#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n;

int main(){
	while(cin >> n){
		int cnt=1;
		int p=2;
		while(p!=1){
			if(p <= n/2){
				p = 2*p;
			}else{
				p = 2*(p-n/2)-1;
			}
			cnt++;
		}	
		cout << cnt << endl;
	}
	return 0;
}

