#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>

using namespace std;

string addBinary(string a, string b){
  	bitset<64> bit_a (a);
  	bitset<64> bit_b (b);
  	unsigned long long ret = bit_a.to_ulong() + bit_b.to_ulong();
  	bitset<64> bit_re (ret);

  	bool start = false;
  	string s = "";
  	for(int i=63;i>=0;i--){
  		if(!start){
	  		if(bit_re[i]){
	  			start = true;
	  			s+="1";
	  		}
  		}else{
			s+= bit_re[i]?"1":"0";	
  		}
  	}
  	return s;
}

int main()
{
	string a = "11";
	string b = "1";
	cout << addBinary(a,b) << endl;
	return 0;
}