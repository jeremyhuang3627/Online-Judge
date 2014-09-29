#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int>& A) {
    int n = A.size();
    int i = n - 1;
    int result = -1;
    int k = 0;
    int maximal = 0;
    while (i > 0) {
    	cout << "result " << result << " i " << i << endl;
        if (A[i] == 1) {
            k = k + 1;
            if (k >= maximal) {
                maximal = k;
                result = i;
            }
        } else {
            k = 0;
        }
        i = i - 1;
    }
    if (A[i] == 1 && k + 1 >= maximal)
        result = 0;
    return result;
}

int main()
{
	int a[5] = {0,0,0,0,0};
	std::vector<int> v (a,a+5);
	cout << solution(v) << endl;
	return 0;
}