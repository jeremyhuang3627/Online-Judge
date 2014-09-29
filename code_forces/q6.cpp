//I Can Guess the Data Structure
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

bool isReverse(vector<int> &t,vector<int> &t2)
{
	if(t.size() != t2.size()){
		return false;
	}

	for(int i=0;i<t.size();i++)
	{
		if(t[i] != t2[t.size()-1-i]){
			return false;
		}
	}

	return true;
}

bool isSameSeq(vector<int> &t,vector<int> &t2)
{
	if(t.size() != t2.size()){
		return false;
	}

	for(int i=0;i<t.size();i++)
	{
		if(t[i] != t2[i])
		{
			return false;
		}
	}

	return true;
}

string getType(vector<pair<int,int> > &v)
{
	int numTrue = 3;
	bool isQueue = true;
	bool isStack = true;
	bool isPriorityQ = true;

	int maxN = 0;
	bool firstOut = true;
	vector<int> t;
	vector<int> t2;
	
	for(int i=0;i<v.size();i++)
	{
		switch(v[i].first){
			case 1:
				maxN = max(maxN,v[i].second);
				t.push_back(v[i].second);
				break;
			case 2:
				if(firstOut){
					firstOut = false;
					if(v[i].second != maxN){
						isPriorityQ = false;
					}
				}
				t2.push_back(v[i].second);
				break;
		}
	}

	if(!isPriorityQ){
		numTrue --;
	}

	if(!isReverse(t,t2)){
		isStack = false;
		numTrue --;
	}
	
	if(!isSameSeq(t,t2)){
		isQueue = false;
		numTrue --;
	}

	string type = "";
	if(numTrue > 1){
		type = "not sure";
	}else if(numTrue == 1){
		if(isQueue){
			type = "queue";
		}

		if(isStack){
			type = "stack";
		}

		if(isPriorityQ){
			type = "priority queue";
		}
	}else{
		type = "impossible";
	}
	return type;
}

int main(){
	while(true){
		int n;
		cin >> n;
		if(cin.eof()){
			break;
		}
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			int op,num;
			cin >> op >> num;
			v.push_back(make_pair(op,num));
		}
		string type = getType(v);
		cout << type << endl;
		
	}
	return 0;
}

