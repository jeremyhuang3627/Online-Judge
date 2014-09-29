#include <iostream>
#include <vector>
using namespace std;

#define W 1001
#define H 1001

int M,N,E,g[W][H],dist[W][H],x,y,curT=0,minT;
vector<pair<int,int> > q;

pair<int,int> popMin()
{	
	int idx,mm = 1E9;
	for(int i=0;i<q.size();i++){
		if(dist[q[i].first][q[i].second] < mm){
			mm = dist[q[i].first][q[i].second];
			idx = i;
		}
	}
	pair<int,int> p = q[idx];
	q.erase(q.begin() + idx);
	return p;
}

void insert(pair<int,int> p){
	int lo = 0,hi = q.size()-1;
	while(lo<=hi){
		int mid = (lo + hi)/2;
		if(dist[q[mid].first][q[mid].second] >= dist[p.first][p.second]){
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}
	q.insert(q.begin() + lo,p);
}

void dijk(){
	dist[M-1][N-1] = g[M-1][N-1];
	q.push_back(make_pair(M-1,N-1));
	while(!q.empty()){
		pair<int,int> p = q.front();//popMin();
		q.erase(q.begin());
		//cout << "p.first " << p.first << " p.second " << p.second << endl;
		if(p.first-1 >=0 && dist[p.first-1][p.second] > dist[p.first][p.second] + g[p.first-1][p.second]){
			dist[p.first-1][p.second] = dist[p.first][p.second] + g[p.first-1][p.second];
			//q.push_back(make_pair(p.first-1,p.second));
			insert(make_pair(p.first-1,p.second));
		}

		if(p.second-1 >= 0 && dist[p.first][p.second - 1] > dist[p.first][p.second] + g[p.first][p.second - 1]){
			dist[p.first][p.second - 1] = dist[p.first][p.second] + g[p.first][p.second - 1];
			//q.push_back(make_pair(p.first,p.second - 1));
			insert(make_pair(p.first,p.second-1));
		}
	}
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	cin >> M >> N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >>g[i][j];
			dist[i][j] = 1E9;
		}
	}

	dijk();

/*	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	} */

	cin >> E;
	for(int i=0;i<E;i++){
		cin >> x >> y;
		cout << dist[x][y] << endl;
	}
    return 0;
}