#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int a = 1;
	cout << "sizeof(a) " << sizeof(a) << endl;

	for(int i=1;i<10;i++){
		cout << "i " << i << " i&(-i) " << (i&(-i)) << endl;
		bitset<32> s1 (i);
		bitset<32> s2 (-i);
		cout << "bin form i "; 
		cout << s1.to_string() << endl;
		cout << "bin form -i ";
		cout << s2.to_string() << endl;
	}
	return 0;
}