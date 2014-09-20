#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int r = matrix.size(),c = matrix.size() ? matrix[0].size() : 0;
	int lo = 0,hi = r*c-1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(matrix[mid/c][mid%c] < target) lo = mid + 1;
		else if(matrix[mid/c][mid%c] > target) hi = mid - 1;
		else return true;
	}
	return false;
}

int main()
{

	return 0;
}