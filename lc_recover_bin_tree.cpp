#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * prevNode;
vector<TreeNode *> badNodes;

void dfs(TreeNode * root)
{
	if(root!=NULL){
		dfs(root->left);

		if(prevNode != NULL && root->val <= prevNode->val){
			badNodes.push_back(prevNode);
			badNodes.push_back(root);
		}
		prevNode = root;

		dfs(root->right);
	}
}

void recoverTree(TreeNode * root)
{
	prevNode = NULL;
	dfs(root);
	if(badNodes.size() == 2)
	{
		int t = badNodes[0]->val;
		badNodes[0]->val = badNodes[1]->val;
		badNodes[1]->val = t;
	}else if(badNodes.size() == 4)
	{
		int t = badNodes[0]->val;
		badNodes[0]->val = badNodes[3]->val;
		badNodes[3]->val = t;
	}
}

void print(TreeNode * r)
{
	if(r)
	{
		print(r->left);
		cout << r->val << " ";
		print(r->right);
	}
}

int main()
{
	TreeNode * r = new TreeNode(3) ;
	r->left = new TreeNode(1);
	r->right = new TreeNode(2);

	recoverTree(r);
	print(r);
	return 0;
}