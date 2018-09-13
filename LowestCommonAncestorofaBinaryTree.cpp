#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL) return NULL;
	if (root == p || root == q) return root;

	TreeNode *L = lowestCommonAncestor(root->left, p, q);
	TreeNode *R = lowestCommonAncestor(root->right, p, q);

	if (L && R) return root;

	return L ? L : R;
}

/*

int main(void) {

}

*/