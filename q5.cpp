#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

int main(){
	while(true){
		int c;
		cin >> c;
		if(cin.eof()){
			break;
		}
		map<int,ull> m;
		for(int i=0;i<c;i++){
			ull n;
			cin >> n;
			m.clear();
			char ch;
			ull p;
			for(int j=0;j<n;j++)
			{	
				cin >> ch >> p;
				m[(int)ch] = p;
			}
			int ln;
			cin >> ln;
			string l;
			ull tp = 0;
			for(int j=0;j<=ln;j++)
			{	
				getline(cin,l);
				const char * cstr = l.c_str();
				while((*cstr)!='\0'){
					tp+= m[(int)(*cstr)];
					//cout << *cstr << " is "<< m[(int)(*cstr)] << endl;
					cstr++;
				}
			}
			if(tp%100 < 10){
				cout << tp/100 << "." << "0" << tp%100 << "$" << endl;
			}else{
				cout << tp/100 << "." << tp%100 << "$" << endl;
			}
		}
	}
	return 0;
}