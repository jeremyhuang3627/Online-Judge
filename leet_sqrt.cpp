#include <iostream>

using namespace std;

int sqrt(int x) {
    int lo=0,hi=x;
    long long m;
    while(lo < hi){
    	m = (lo + hi)/2;
    	if(m*m>x){
    		hi = m-1;
    	}else if(m*m<x){
    		lo = m+1;
    	}else{
    		return m;
    	}
    }

    if(lo*lo > m){
    	lo -= 1;
    }
    return lo;
}

int main(){
	int t = 0;
	cout << "sqrt "<< t << " "<< sqrt(t) << endl;
	return 0;
}