#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

double x,y,n;

using namespace std;

int main()
{
	cin >> x >> y >> n;
	if(y>n){
		double a = x, b = n;
		
		while(true){
			double diff = abs(x/y - a/b);
			bool next = false;

			double res1,res2,res3;
			res1 =  (b-1) ? diff - abs(x/y - a/(b-1)):-1E9;
			res2 = diff - abs(x/y - (a-1)/(b));
			res3 = (b-1) ? diff - abs(x/y - (a-1)/(b-1)):-1E9;

		//	cout << "abs(x/y - a/b) " << abs(x/y - a/b) << endl;

		//	cout << "abs(x/y - a/(b-1)) " <<  abs(x/y - a/(b-1)) << endl;

		//	cout << "abs(x/y - (a-1)/(b)) " <<  abs(x/y - (a-1)/(b)) << endl;

		//	cout << "abs(x/y - (a-1)/(b-1)) " <<  abs(x/y - (a-1)/(b-1)) << endl;

			if(res1 > res2){
				if(res1 > res3){

				}else{

				}
			}else{
				if(res2 > res3){

				}else{

				}
			}


			if(!next) break;
		}

		cout << (int)a << "/" << (int)b << endl;
	}else{
		cout << x << "/" << y << endl;
	}
	return 0;
}