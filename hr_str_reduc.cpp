#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

string s;
int a[3],ans,t;

int main() {
    cin >> t;
    while(t--){
        cin >> s;
        fill_n(a,3,0);
        for(int i=0;i<s.length();i++) a[s[i]-'a']++;
        bool all_odd = true,all_even = true; int zcnt = 0;
        for(int i=0;i<3;i++){
          //  cout << "a["<< i << "] " << a[i] << endl;
            if(a[i]==0)zcnt++;
            if(a[i]%2==1) all_even = false;
            if(a[i]%2==0) all_odd = false;
        }
       // cout << "zcnt " << zcnt << endl;
        if(zcnt==2) ans = s.length();
        else if(all_odd || all_even) ans = 2; 
        else ans = 1;
        cout << ans << endl;
    }
    return 0;
}
