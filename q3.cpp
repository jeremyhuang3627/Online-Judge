//code chef Retail Shop
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

vector<int> v;
vector<vector<int> > vs;

int intpow(int x,int e){
	int ret = 1;
	for(int i=0;i<e;i++)
	{
		ret *= x;
	}
	return ret;
}

void choose(vector<int> &allNums,int l){
	if(l==0){
		vs.push_back(v);
	}else{
		for(int i=0;i<allNums.size();i++)
		{
			v.push_back(allNums[i]);
			choose(allNums,l-1);
			v.pop_back();
		}
	}
}	

vector<vector<int> > perm(vector<int> &allNums,int n)
{	
	v.clear();
	vs.clear();
	choose(allNums,n);
	return vs;
}

vector<int> breakDigits(int n)
{
	vector<int> t;
	while(n!=0)
	{
		int re = n%10;
		n = n/10;
		t.push_back(re);
	}

	return t;
}

bool checkOk(int p1,int p2, vector<int> &nums)
{	
	if(p1 > 1000 || p1 < 100 || p2 > 1000 || p2 < 100 ){
		return false;
	}

	vector<int> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p1*p2);

	bool ok = false;

	for(int i=0;i<v.size();i++){
		vector<int> temp = breakDigits(v[i]);
		for(int j=0;j<temp.size();j++)
		{	
			if(find(nums.begin(),nums.end(), temp[j]) == nums.end()){
				return false;
			}	
		}
	}

	return true;
}


int getNumSol(vector<vector<int> > m1,vector<vector<int> > m2,vector<int> allNums)
{
	int cnt = 0;
	for(int i=0;i<m1.size();i++)
	{
		for(int j=0;j<m2.size();j++)
		{
			int num1 = 0; 
			for(int l=0;l<m1[i].size();l++)
			{
				//cout << "m1["<< i << "]["<< l <<"] " << m1[i][l] << " m1["<< i <<"].size()-l-1 " << m1[i].size()-l-1<< endl;
				num1 += m1[i][l] * intpow(10,m1[i].size()-l-1);
			} 
 			
			int pp1 = num1 * m2[j][1];
			int pp2 = num1 * m2[j][0]; //partial product one or two

			bool ok = checkOk(pp1,pp2,allNums);
	
			if(ok){
				cnt ++;
			}
		}
	}
	return cnt;
}

int main(){
	int caseNum;
	cin >> caseNum;
	vector<int> allNums;

	for(int i=0;i<caseNum;i++){
		int num;
		cin >> num;
		allNums.push_back(num);
	}

	vector<vector<int> > m1 = perm(allNums,3);
	vector<vector<int> > m2 = perm(allNums,2);

	int numSol = getNumSol(m1,m2,allNums);
	cout << numSol << endl;

	return 0;
}