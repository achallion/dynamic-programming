#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return -1;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (slow != fast)
    {
        if (slow->next == NULL || fast->next->next == NULL)
        {
            return -1;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    fast = head;
    int i = 0;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
        i++;
        if (slow == fast)
        {
            break;
        }
    }
    return i;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

pair<TreeNode *, TreeNode *> find(TreeNode *par, TreeNode *root, int k)
{
    // base
    if (root == NULL)
        return {NULL, NULL};

    if (root->val)
    {
        return {par, root};
    }

    // rec
    if (k <= root->val)
    {
        return find(root, root->left, k);
    }
    return find(root, root->right, k);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val == key)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
    }

    pair<TreeNode *, TreeNode *> node = find(NULL, root, key);
    TreeNode *par = node.first;
    TreeNode *cur = node.second;
    // if no child
    if (cur->left == NULL && cur->right == NULL)
    {
        delete cur;
        if (par->left == cur)
        {
            par->left == NULL;
        }
        if (par->right == cur)
        {
            par->right == NULL;
        }
        return root;
    }

    // if 1 child
    if (cur->left == NULL)
    {
        if (par->left == cur)
        {
            par->left = cur->right;
        }
        else
        {
            par->right = cur->right;
        }
        return root;
    }

    if (cur->right == NULL)
    {
        if (par->left == cur)
        {
            par->left = cur->left;
        }
        else
        {
            par->right = cur->left;
        }
        return root;
    }

    // if 2 child
    TreeNode *child = cur->left;
    TreeNode *parchild = cur;
    while (child->left != NULL && child->right != NULL)
    {
        parchild = child;
        child = child->right;
    }
    cur->val = child->val;
    delete parchild->right;
    parchild->right = NULL;
    return root;
}
