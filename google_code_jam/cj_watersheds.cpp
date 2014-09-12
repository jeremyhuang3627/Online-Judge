#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <bitset>
#include <map>
#include <string>

using namespace std;

#define M 10005
#define min(a,b) ((a>b)? b:a)

int m[105][105],T,H,W,c;
char label[105][105];

char dfs(int i,int j){
	//cout << "i " << i << " j " << j << " m[i][j] " << m[i][j] << " label[i][j] " << label[i][j]-'a' << endl;
	if(label[i][j]-'a' >= 0){
		return label[i][j];
	}

	int l,r,t,d,low=m[i][j],direction=-1;
	l=r=t=d=M;
	if(i>0){
		t=m[i-1][j];
		if(t<low){
			low = t;
			direction = 0;
		}
	}

	if(j>0){
		l=m[i][j-1];
		if(l<low){
			low = l;
			direction = 1;
		}
	}

	if(i<H-1){
		d=m[i+1][j];
		if(d<low){
			low = d;
			direction = 2;
		}
	}

	if(j<W-1){
		r=m[i][j+1];
		if(r<low){
			low = r;
			direction = 3;
		}
	}

	//cout << "direction " << direction << endl;
	if(direction==-1){
		label[i][j] = ('a' + c);
		c++;
		return label[i][j];
	}else{
		switch(direction){
			case 0:
				label[i][j] = dfs(i-1,j);
				break;
			case 1:
				label[i][j] = dfs(i,j-1);
				break;
			case 2:
				label[i][j] = dfs(i+1,j);	
				break;
			case 3:
				label[i][j] = dfs(i,j+1);
				break;
		}
		return label[i][j];
	}
}

int main()
{
	cin >> T;
	for(int k=1;k<=T;k++)
	{
		cin >> H >> W;
		memset(label,0,sizeof(label));
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++){
				cin >> m[i][j];
			}
		}

		c=0;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++){
				if(label[i][j]-'a' < 0){
					dfs(i,j);
				}
			}
		}

		cout << "Case #"<< k << ":" << endl;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++){
				cout << label[i][j];
				if(j!=W-1){
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}