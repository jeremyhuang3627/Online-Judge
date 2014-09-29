#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair <int, int> pii;
const int MAX_N = int (1e5) + 7;

int ans [MAX_N];
pii query [MAX_N], x [MAX_N];

inline bool comp (const pii &a, const pii &b) { return (a.first < b.first) || (a.first == b.first && a.second > b.second); }

int main () {
    int t, cs = 1;

    for (scanf ("%d", &t); cs <= t; ++cs) {
        int n, m, cur = 0;
        scanf ("%d %d", &m, &n);

        for (int i = 0; i < m; ++i) scanf ("%d %d", &query [i].first, &query [i].second);
        for (int i = 0; i < n; ++i) { scanf ("%d", &x [i].first); x [i].second = i; }

        cout << "t1 " << endl;
        sort (query, query + m, comp);
        sort (x, x + n);

        for (int i = 0; i < m; ++i){
            cout << query[i].first << " " << query[i].second << endl;
        }


        for (int i = 1; i < m; ++i) if (query [i].second > query [cur].second) query [++cur] = query [i];

        //print query: 
        cout << "t2 " << endl;
        for (int i = 0; i < m; ++i){
            cout << query[i].first << " " << query[i].second << endl;
        }
        m = cur + 1; cur = 0;

        for (int i = 0; i < n; ++i) {
            cout << "x["<< i << "].first " << x[i].first << " " << " x[" << i << "].second " << x[i].second << endl;
            int px = x [i].first;
            int &mn = ans [x [i].second] = 0;

            if (cur >= m) cur = m - 1;
            while (cur < m && px >= query [cur].first) {
                if (px >= query [cur].second) { ++cur; continue; }
                int val = min (px - query [cur].first, query [cur].second - px);
                if (val < mn) break;
                mn = val;
                ++cur;
            }
            --cur;
        }

        printf ("Case %d:\n", cs);
        for (int i = 0; i < n; ++i) printf ("%d\n", ans [i]);
    }

    return 0;
}