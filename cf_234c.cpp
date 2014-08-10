#include <fstream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath> 

using namespace std;

#define F(i,a,n) for(int i=a;i<n;i++)
#define ULL unsigned long long
#define LL long long
#define max(a,b) (a > b ? a : b )
#define min(a,b) (a > b ? b : a )

int a [100000 + 100];

int main(){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n;
	fin>>n;
	int r [3] = {0};
	int l [3] = {0};
	F(i,0,n){
		fin >> a[i];
		//scanf("%d",&a[i]);
		if(a[i]>0) r[2] ++; // 2 is positive
		else if(a[i]<0) r[1] ++; // 1 is negative
		else r[0] ++; // 0 is zeros
	}

	int minChg = n;
	F(i,0,n-1){
		if(a[i]>0){
			l[2] ++;
			r[2] --;
		}else if(a[i]<0){
			l[1] ++;
			r[1] --;
		}else{
			l[0] ++;
			r[0] --;
		}
		if(r[0] != n - i - 1){
			minChg = min(minChg,l[0] + r[0] + l[2] + r[1]);
		}
	}

	fout << minChg << endl;
	return 0;
}