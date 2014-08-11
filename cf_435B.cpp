#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long a,k;

void swap(vector<int> &v, int i,int j){
	int d = v[j];
	v[j] = v[i];
	v[i] = d;
}

vector<int> intToVect(long long a){
	vector<int> v;
	while(a){
		v.push_back(a%10);
		a /= 10; 
	}

	for(int i=0;i<v.size()/2;i++){
		swap(v,i,v.size() - 1 - i);
	}
	return v;
}

int main(){
	cin >> a >> k;
	vector<int> v = intToVect(a);

	if(v.size() > 1){
		int i=0;
		while(k && i < v.size()){
			int m = v[i];
			int m_idx = i;
			for(int j = i + 1;j<=i + k && j < v.size();j++){
				if(v[j] > m){
					m = v[j];
					m_idx = j;
				}
			}

			while(m_idx - i !=0){
				swap(v,m_idx - 1,m_idx);
				m_idx --;
				k--;
			}

			i++;
		}

		for(int i=0;i<v.size();i++){
			cout << v[i];
		}
		cout << endl;
	}else{
		cout << a << endl;
	}
	return 0;
}