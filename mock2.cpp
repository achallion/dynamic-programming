#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

int height(TreeNode *root)
{
    // base
    if (root == NULL)
    {
        return -1;
    }

    // rec

    return max(height(root->left), height(root->right)) + 1;
}

bool check(TreeNode *root, int h, int aheight)
{
    // base

    // rec
    if (h == aheight)
    {
        if(root->right != NULL && root->left == NULL)
        {
            return false;
        }
    }
    if (root->left == NULL || root->right == NULL)
    {
        return false;
    }
    return true;
}

bool isCompleteTree(TreeNode *root)
{
    int h = height(root);
    bool c = check(root, 0, h - 1);
    return c;
}