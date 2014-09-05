#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define M 105

int n,d,l,a[M],i;

int main()
{
	cin >> n >> d >> l;
	fill_n(a,n,1);
	int s = (n%2==1);
	bool ok = false;

	if(s!=d){
		if(s<=d)
		{
			for(int i=0;i<n;i+=2)
			{
				a[i] += min(d-s,l-1);
				s += min(d-s,l-1);

				if(s == d){
					ok = true;
					break;
				}
			}
		}else if(s > d){
			for(int i=1;i<n;i+=2)
			{
				a[i] += min(s-d,l-1);
				s -= min(s-d,l-1);
				if(s == d){
					ok = true;
					break;
				}
			}
		}
	}else{
		ok = true;
	}

	if(ok){
		for(int i=0;i<n;i++){
			cout << a[i] << " ";
		}
	}else{
		cout << -1 << endl;
	} 

	return 0;
}