#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int i=0,j=0;
	//cout << " A.size() " << A.size() << " B.size() " << B.size() << endl;
	while(i<A.size() && j<B.size())
	{	
		//cout << "i " << i << " j " << j << endl;
		if(A[i]==B[j]){
			return A[i];
		}else if(A[i] > B[j]){
			j++;
		}else{
			i++;
		}
	}
	return -1;
}

int main(){
	int a[4] = {1, 3, 2, 1};
	vector<int> A (a,a+4);

	int b[5] = {4, 2, 5, 3, 2};
	vector<int> B (b,b+5);

	cout << solution(A,B) << endl; 
	return 0;
}