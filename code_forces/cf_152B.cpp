#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define min(a,b) ((a<b)?a:b)

long long n,m,x,y,k,vx,vy,sx,sy,s,t=0;

int main(){
	cin >> n >> m >> x >> y >> k;
	while(k--){
		cin >> vx >> vy;
	//	cout << "x " << x << " y " << y << endl;
	//	cout << "vx " << vx << " vy " << vy << endl;
		sx = (vx !=0 ? (vx>0?(n-x):x-1)/abs(vx) : 0);
		sy = (vy !=0 ? (vy>0?m-y:y-1)/abs(vy) : 0);
	//	cout << "sx " << sx << " sy " << sy << endl;
		s = (vx==0 || vy==0)? sx+sy:min(sx,sy);
		x += vx*s;
		y += vy*s;
		t+=s;
	//	cout << "s " << s << endl;
	}
	cout << t << endl;
	return 0;	
}