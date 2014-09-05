#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;


#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

#define MAX_NODE 2000000
struct SegmentTree
{
	int left, right, sum;
	SegmentTree(int l = 0, int r = 0, int s = 0) {left = l, right = r, sum = s;}
};

SegmentTree segmentTree[MAX_NODE];
int node[MAX_NODE], nnode;

int a[100005], n;
PII V[100005];

int insert(int at, int left, int right, int pos, int val)
{
	/* Create new node if necessary */
	int cur = nnode++;
	if(at != -1) segmentTree[cur] = segmentTree[at];
	else		 segmentTree[cur] = SegmentTree(-1, -1, 0);
	at = cur;

	/* Add number to current node */
	segmentTree[at].sum += val;

	if(left == right) return at;

	int mid = (left + right) >> 1;

	/* Go to correct branch */
	if(pos <= mid)	segmentTree[at].left  = insert(segmentTree[at].left , left,      mid, pos, val);
	else			segmentTree[at].right = insert(segmentTree[at].right, mid + 1, right, pos, val);

	return at;
}

int querySegmentTree(int at, int L, int R, int l, int r)
{
	if(at == -1) return 0;
	if(l <= L && R <= r) return segmentTree[at].sum;
	if(r < L || R < l) return 0;
	int mid = (L + R) >> 1;
	return querySegmentTree(segmentTree[at].left, L, mid, l, r) + querySegmentTree(segmentTree[at].right, mid + 1, R, l, r);
}

int query(int l, int r)
{
	int id, sum = 0, cur;
	while(1)
	{
		id = upper_bound(V, V + n, PII(sum + 1, n + 1)) - V;
		cur = querySegmentTree(node[id], 1, n, l, r);
		if(cur == sum) return sum + 1;
		sum = cur;
	}

	return -1;
}

int main()
{
	int sa = 0, i, j = 0;
	int m;
	int l, r;

	scanf("%d", &n);
	AIN(n, 1, 100000);

	FORAB(i, 1, n) 
	{
		scanf("%d", &a[i]);	AIN(a[i], 1, 1000000000);
		sa += a[i];			AIN(sa, 1, 1000000000);
		V[j++] = PII(a[i], i);
	}

	sort(V, V + n);

	/* Initial tree */
	nnode = 0;
	node[0] = -1;

	/* Create Segment Tree incrimentally */
	FORAB(i, 1, n)
	{
		node[i] = insert(node[i - 1], 1, n, V[i - 1].second, V[i - 1].first);
	}

	scanf("%d", &m);
	AIN(m, 1, 100000);

	while(m--)
	{
		scanf("%d %d", &l, &r);
		AIN(l, 1, r); AIN(r, l, n);
		printf("%d\n", query(l, r));
	}

	return 0;
}
