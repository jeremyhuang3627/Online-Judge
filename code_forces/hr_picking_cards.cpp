#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MX 50000
#define MOD 1000000007

int T,N,a[MX],cnt[MX];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++){
        	cin >> a[i];
        	cnt[a[i]]++;
        }
        int ret = 1;
        for(int i=0;i<N;i++){
        	if(cnt[i]) ret = (ret * cnt[i])%MOD;
        }
        cout << ret << endl;
    }
    return 0;
}