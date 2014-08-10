#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int rn [51];
int t [51][51];
vector<vector<int> > steps;

void swap(int i,int j,int x, int y){
	int temp = t[i][j];
	t[i][j] = t[x][y];
	t[x][y] = temp;

	int a [4] = {i+1,j+1,x+1,y+1};
	steps.push_back(vector<int>(a,a+4));
}

void print(int n){
	F(i,0,n){
		F(j,0,rn[i]){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n;

	scanf("%d",&n);

	F(i,0,n){
		scanf("%d",&rn[i]);
	}

	F(i,0,n){
		F(j,0,rn[i]){
			scanf("%d",&t[i][j]);
		}
	}

	int i=0;
	int j=0;

	while(i<n){
		//print(n);
		if(j<rn[i]-1 && t[i][j] > t[i][j+1]){
			swap(i,j,i,j+1);
			// i,j remains at this position;
		}else if(i<n-1 &&  j<rn[i+1] && t[i][j] > t[i+1][j]){
			swap(i,j,i+1,j);
		}else if(i>0 && t[i][j] < t[i-1][j]){
			swap(i,j,i-1,j);
			i = i - 1; 
		}else if(j>0 && t[i][j] < t[i][j-1]){
			swap(i,j,i,j-1);
			j = j-1;
		}else{
			j++;
			if(j>=rn[i]){
				i++;
				j = 0;
			}
		}
	}


	cout << steps.size() << endl;
	F(i,0,steps.size()){
		cout << steps[i][0] << " " << steps[i][1] << " " << steps[i][2] << " " << steps[i][3] << endl; 
	}

	return 0;
}