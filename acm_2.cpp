#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<string> v;
string s;

int main(){
	for(int i=0;i<4;i++){
		cin >> s;
		v.push_back(s.substr(2));
	}

	int cnt = 0,ans;
	for(int i=0;i<4;i++){
		bool sht = true;
		for(int j=0;j<4;j++){
			if(i!=j){
				if(v[i].length()*2 > v[j].length()){
					sht = false;
				}
			}
		}

		bool lon = true;
		for(int j=0;j<4;j++){
			if(i!=j){
				if(v[i].length() < v[j].length()*2){
					lon = false;
				}
			}
		}
		if(lon || sht){
			cnt++;
			ans = i;
		}
	}

	if(cnt==1){
		//cout << "ans " << ans << endl;
		printf("%c\n",ans+'A');
	}else{
		cout << "C" << endl;
	}
	return 0;
}