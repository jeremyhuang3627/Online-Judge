//code chef Root of the Problem
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <tr1/unordered_map>
#include <ctime>
#include <cctype>
#include <cmath>

using namespace std;

int main(){
	int numTest;
	cin >> numTest;
	for(int i=0;i<numTest;i++){
		int numNode;
		cin >> numNode;
		int idSum = 0;
		int nodeChildrenIdSum = 0;
		for(int j=0;j<numNode;j++){
			int id,cidSum;
			cin >> id >> cidSum;
			idSum += id;
			nodeChildrenIdSum += cidSum;
		}
		cout << idSum - nodeChildrenIdSum << endl; 
	}

	return 0;
}