#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 1000
int a[M],b[M],n,x,t;

bool cmp(int a,int b){
	return a > b;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
		}

		for(int i=0;i<n;i++)
		{
			scanf("%d",b+i);
		}

		sort(a,a+n);
		sort(b,b+n,cmp);

		long long sum = 0;
		for(int i=0;i<n;i++){
			sum += a[i] * b[i];
		}
		cout << sum << endl;
	}

	return 0;
}