 1 /*
 2  Problem link
 3  Type: DP
 4  Algorithm: Coin change
 5  */
 6  #include <iostream>
 7  #include <cstdio>
 8  #include <cmath>
 9  #include <cstring>
10  using namespace std;
11  
12  const char* fi = "11137.inp";
13  const char* fo = "11137.out";
14  const int CubeCur[22] = {0,1,8,27,64,125,216,343,512,729,1000,1331,
15                           1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
16  const int maxn = 10010;
17  
18  long long f[maxn][25];
19  int n;
20  
21  void solve();
22  
23  int main()
24  {
25      //freopen(fi,"r",stdin);
26      //freopen(fo,"w",stdout);
27      solve();
28      while (!cin.eof())
29      {
30          cin >> n;
31          if (cin.eof()) break;
32          cout << f[n][21] << endl;
33      }
34      return 0;
35  }
36  
37  void solve()
38  {
39      for (int i=0; i<=10000; i++)
40          for (int j=0; j<=21; j++) f[i][j] = 0;
41      for (int j=0; j<=21; j++) f[0][j] = 1;
42  
43      for (int i=1; i<=10000; i++)
44          for (int j=1; j<=21; j++)
45              if (CubeCur[j]<=i) f[i][j] = f[i-CubeCur[j]][j] + f[i][j-1];
46              else f[i][j] = f[i][j-1];
47  }