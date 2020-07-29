#include <bits/stdc++.h>

using namespace std;
string restoreString(string s, vector<int> &indices)
{
    string ans(s);
    for (int i = 0; i < s.size(); i++)
    {
        ans[indices[i]] = s[i];
    }
    return ans;
}

bool same(char target, bool cur)
{
    if (target == '0' && cur == false)
    {
        return true;
    }
    if (target == '1' && cur == true)
    {
        return true;
    }
    return false;
}

int minFlips(string target)
{
    string ans;
    bool cur = false;
    int flip = 0;
    for (int i = 0; i < target.size(); i++)
    {
        if (same(target[i], cur)) // base
        {
            ans.push_back(target[i]);
            continue;
        }
        // diff
        cur = !cur;
        ans.push_back(target[i]);
        flip++;
    }
    return flip;
}

/////////////////

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define pvii pair<vector<int>, int>
int coun = 0;
pvii dorec(TreeNode *root, int dist)
{
    // base

    if (root == NULL)
    {
        pvii temp;
        temp.second = 0;
        return temp;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pvii temp;
        temp.second = 0;
        temp.first.push_back(1);
    }

    // rec
    pvii l, r, ans;
    l.second = 0;
    r.second = 0;
    ans.second = 0;
    if (root->left != NULL)
    {
        l = dorec(root->left, dist);
    }
    if (root->right != NULL)
    {
        r = dorec(root->right, dist);
    }
    for (int i = 0; i < l.first.size(); i++)
    {
        for (int j = 0; j < r.first.size(); j++)
        {
            if (l.first[i] + r.first[j] <= dist)
            {
                ans.second++;
            }
        }
    }
    ans.second += (l.second + r.second);
    for (int i = 0; i < l.first.size(); i++)
    {
        if (l.first[i] < dist)
        {
            ans.first.push_back(l.first[i] + 1);
        }
    }
    for (int i = 0; i < r.first.size(); i++)
    {
        if (r.first[i] < dist)
        {
            ans.first.push_back(r.first[i] + 1);
        }
    }
    return ans;
}

int countPairs(TreeNode *root, int distance)
{
    coun = 0;
    pvii ans = dorec(root, distance);
    return coun;
}