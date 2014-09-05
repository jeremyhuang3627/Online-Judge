#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stack>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};

bool cmp(Interval i1,Interval i2){
	if(i1.start != i2.start) return (i1.start < i2.start) ;
	else return i1.end < i2.end;
}

bool overlap(Interval i,Interval j)
{
	return (i.start >= j.start && i.start <=j.end) || (j.start >= i.start && j.start <= i.end);
}

vector<Interval> merge(vector<Interval> &intervals)
{
	sort(intervals.begin(),intervals.end(),cmp);
	vector<Interval> s;
	s.push_back(intervals[0]);
	for(int i=1;i<intervals.size();i++)
	{
		Interval ii = s.back();
		if(overlap(ii,intervals[i])){
			//cout << ii.start << "," << ii.end << " overlaps with " << intervals[i].start << " , " << intervals[i].end << endl; 
 			s.pop_back();
			Interval ni (ii.start,intervals[i].end);
			s.push_back(ni);
		}else{
			s.push_back(intervals[i]);
		}
	}
	return s;
}

int main()
{

	vector<Interval> intervals;
	Interval i1 (1,3);
	intervals.push_back(i1);
	Interval i2 (8,10);
	intervals.push_back(i2);
	Interval i3 (2,6);
	intervals.push_back(i3);

	vector<Interval> ans = merge(intervals);

	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i].start << "," << ans[i].end << endl;
	}

	return 0;
}