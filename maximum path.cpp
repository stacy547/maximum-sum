// C/C++ program to find maximum path sum in Binary Tree
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
struct Node* newNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return (newNode);
}


int findMaxUtil(Node* root, int& res)
{
	if (root == NULL)
		return 0;
	int l = findMaxUtil(root->left, res);
	int r = findMaxUtil(root->right, res);
	int max_single
		= max(max(l, r) + root->data, root->data);
	int max_top = max(max_single, l + r + root->data);

	res = max(res, max_top); 

	return max_single;
}
int findMaxSum(Node* root)
{
	int res = INT_MIN;
	findMaxUtil(root, res);
	return res;
}
int main(void)
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	cout << "Max path sum is " << findMaxSum(root);
	return 0;
}
