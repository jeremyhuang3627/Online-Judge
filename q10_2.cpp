//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef vector<int> VI;

struct Node{
	string name;
	Node * head;
	Node * next;
	int cnt;
	Node(string n):name(n),head(NULL),next(NULL),cnt(1){}
};

int main(){
	int cn;
	cin >> cn;
	for(int i=0;i<cn;i++)
	{
		int fn;
		cin >> fn;
		tr1::unordered_map<string,Node *> m;
		tr1::unordered_map<Node *,Node *> circles; 
		for(int j=0;j<fn;j++)
		{
			string n1,n2;
			cin >> n1 >> n2;
			Node * start;
			Node * end;
			if(!m[n1] && !m[n2])
			{
				m[n1] = new Node(n1);
				m[n2] = new Node(n2);
				m[n1]->next = m[n2];
				m[n2]->head = m[n1];
				m[n1]->head = m[n1];
				start = m[n1];
				end = m[n2];
				circles[start] = end;
				m[n1]->cnt ++;
				cout << m[n1]->cnt << endl;
			}else if(!m[n1]){
				Node * head = m[n2]->head;
				m[n1] = new Node(n1);
				circles[head]->next = m[n1];
				circles[head] = m[n1];
				m[n1]->head = head;
				m[n2]->head->cnt++;
				cout << m[n2]->head->cnt << endl;
			}else if(!m[n2]){
				Node * head = m[n1]->head;
				m[n2] = new Node(n2);
				circles[head]->next = m[n2];
				circles[head] = m[n2];
				m[n2]->head = head;
				m[n1]->head->cnt++;
				cout << m[n1]->head->cnt << endl;
			}else{
				Node * head = m[n1]->head;
				Node * head2 = m[n2]->head;
				Node * bigger = m[n1];
				Node * smaller = m[n2];
				if(head != head2){ // move the smaller one to the bigger one;
					if(m[n1]->cnt < m[n2]->cnt){
						bigger = m[n2];
						smaller = m[n1];
					}
					circles[bigger->head]->next = smaller->head;
					Node * cur = smaller;
					while(cur != NULL && cur->next != NULL){
						cur->head = bigger->head;
						cur = cur->next;
						bigger->head->cnt++;
					}
					cur->head = bigger->head;
					bigger->head->cnt ++;
					circles[bigger->head] = cur;
				}
				cout << bigger->head->cnt << endl;
			}
		}
	}
	return 0;
}