#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int n,k;

int main()
{
	cin >> n >> k;
	cout << max(3*n-k,0) << endl;
	return 0;
}