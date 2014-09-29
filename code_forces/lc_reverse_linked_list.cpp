#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode *reverseBetween(ListNode *head,int m,int n)
{
	ListNode * cur=NULL, *temp=NULL,*cur2=NULL,*s = NULL,*e = NULL;
	cur = head;
	int i = 1;
	while(cur != NULL){
		if(i==m-1){
			while(i<n && cur->next != NULL){
				//cout << "i " << i << endl;
				temp = cur->next;
				cur->next = cur->next->next;
				temp->next = NULL;
				if(s==NULL|| e==NULL){
					s = e = temp;
				}else{
					temp->next = s;
					s = temp;
				}
				i++;
			}
			e->next = cur->next;
			cur->next = s;
			break;
		}else if(m==1){
			while(i<=n){
				temp = cur;
				cur = cur->next;
				temp->next = NULL;
				if(s==NULL|| e==NULL){
					s = e = temp;
				}else{
					temp->next = s;
					s = temp;
				}
				i++;
			}
			e->next = cur;
			head = s;
			break;
		}
		cur = cur->next;
		i++;
	}
	return head;
}

int main()
{
	ListNode * head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	ListNode * reverse = reverseBetween(head,2,2);
	ListNode * cur = reverse;

	while(cur!= NULL){
		cout << cur->val << endl;
		cur = cur->next;
	}
	return 0;
}