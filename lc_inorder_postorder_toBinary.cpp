#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode * build(vector<int> &inorder, vector<int> &postorder,int is,int ie,int ps,int pe)
{
	TreeNode * node = NULL;
	//printf("is %d ie %d ps %d pe %d\n",is,ie,ps,pe);
	if(ie - is >= 0 && pe - ps >= 0)
	{
		//printf("is %d ie %d ps %d pe %d\n",is,ie,ps,pe);
		int root = postorder[pe];
		//cout << "root " << root << endl;
		int i=is;
		for(;i<=ie;i++)
		{
			if(inorder[i] == root){
				break;
			}	
		}
		node = new TreeNode(root);
		if(i-is>0 && i <= ie) node->left = build(inorder,postorder,is,i-1,ps,ps+i-is-1);
		if(ie - i > 0 && i>=is) node->right = build(inorder,postorder,i+1,ie,ps+i-is,pe-1);
	}
	return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {   
	 return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
}

void printTree(TreeNode * node)
{
	if(node != NULL)
	{
		printTree(node->left);
		cout << node->val<< " ";
		printTree(node->right);
	}
}

int main()
{
	int post[7] = {1,6,3,8,7,5,4};
	int in[7] = {1,3,6,4,8,5,7};

	vector<int> inorder (in,in + 7);
	vector<int> postorder (post,post+7);

	TreeNode * ans = buildTree(inorder,postorder);

	printTree(ans);

	return 0;
}