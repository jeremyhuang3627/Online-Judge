#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define S 2505
#define N 55

using namespace std;

int n,temp;
int rn [N];
int row [S];
int col [S];
int t [N][N];
int x [N][4];

void print(int n){
	F(i,0,n){
		F(j,0,rn[i]){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	vector<vector<int> > steps;
	scanf("%d",&n);

	F(i,0,n){
		scanf("%d",&rn[i]);
	}

	F(i,0,n){
		F(j,0,rn[i]){
			scanf("%d",&t[i][j]);
			row[t[i][j]] = i;
			col[t[i][j]] = j;
		}
	}

	int cnt = 0;
	F(i,0,n){
		F(j,0,rn[i]){
			cnt ++;
			if(cnt != t[i][j]){
				temp = t[i][j];
				t[i][j] = t[row[cnt]][col[cnt]];
				t[row[cnt]][col[cnt]] = temp;
				row[temp] = row[cnt];
				col[temp] = col[cnt];
				int a [4] = {i + 1,j + 1,row[cnt] + 1,col[cnt] + 1};
				steps.push_back(vector<int>(a,a+4));
				row[cnt] = i;
				col[cnt] = j;
			}
		}
	}

	//print(n);

	cout << steps.size() << endl;
	F(i,0,steps.size()){
		cout << steps[i][0] << " " << steps[i][1] << " " << steps[i][2] << " " << steps[i][3] << endl; 
	}

	return 0;
}