#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > ans;
vector<int> v;
int level = 1;
map<TreeNode *,int> m;

void zigzagbfs(TreeNode * root)
{
	if(root){
		queue<TreeNode *> q;
		m[root] = level;
		int prev_level = level;
		q.push(root);
		while(q.size()!=0){
			TreeNode * n = q.front();
			q.pop();
			level = m[n];
			
			if(prev_level != level){
				ans.push_back(v); 
				v.clear();
			}

			v.push_back(n->val);

			if(n->left) q.push(n->left);
			if(n->right) q.push(n->right);

			m[n->right] = level + 1;
			m[n->left] = level + 1;
			prev_level = level;
		}
		ans.push_back(v); 
	}
}

void reverse(vector<int> &r)
{
	for(int i=0;i<r.size()/2;i++){
		int t = r[r.size()-i-1];
		r[r.size() - i - 1] = r[i];
		r[i] = t;
	}
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
     zigzagbfs(root);
     for(int i=0;i<ans.size();i++)
     {
     	if(i%2==1){
     		reverse(ans[i]);
     	}
     } 
     return ans;  
}

int main()
{
	TreeNode * root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int> > l = zigzagLevelOrder(root);

	for(int i=0;i<l.size();i++){
		for(int j=0;j<l[i].size();j++)
		{
			cout << l[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}