#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int* p = new int[10]();
	for(int i=0;i<10;i++){
		p[i] = i;
	}
	for(int i=0;i<10;i++){
		cout << p[i] << endl;
	}
	return 0;
}