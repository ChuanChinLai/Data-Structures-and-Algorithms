#pragma once

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* minValueNode(TreeNode* root)
{
	TreeNode* current = root;

	while (current->left != nullptr)
	{
		current = current->left;
	}

	return current;
}



TreeNode* deleteNode(TreeNode* root, int key) 
{
	if (root == nullptr)
		return root;

	if (key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == nullptr)
		{
			TreeNode* tmp = root->right;
			delete root;
			return tmp;
		}

		if (root->right == nullptr)
		{
			TreeNode* tmp = root->left;
			delete root;
			return tmp;
		}

		TreeNode* successor = minValueNode(root->right);

		root->val = successor->val;

		root->right = deleteNode(root->right, successor->val);

	}



	return root;
}