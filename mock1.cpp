#include <bits/stdc++.h>

using namespace std;

bool allrotten(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
int helper(vector<vector<int>> &grid, int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    int minute = 0;
    bool anypushed = false;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        int i = f.first;
        int j = f.second;
        if (i != 0 && grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 2;
            q.push({i - 1, j});
            anypushed = true;
        }
        if (i != r - 1 && grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 2;
            q.push({i + 1, j});
            anypushed = true;
        }
        if (j != 0 && grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 2;
            q.push({i, j - 1});
            anypushed = true;
        }
        if (j != c - 1 && grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 2;
            q.push({i, j + 1});
            anypushed = true;
        }
        if (anypushed == true)
        {
            minute++;
            anypushed = false;
        }
    }
}

int orangesRotting(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    int minute = -1;
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    q.push({-1, -1});
    while (q.size() > 1)
    {
        auto f = q.front();
        q.pop();
        if (f.first == -1) // NULL
        {
            q.push(f);
            minute++;
            continue;
        }
        int i = f.first;
        int j = f.second;
        if (i != 0 && grid[i - 1][j] == 1)
        {
            q.push({i - 1, j});
            grid[i - 1][j] = 2;
        }
        if (i != r - 1 && grid[i + 1][j] == 1)
        {
            q.push({i + 1, j});
            grid[i + 1][j] = 2;
        }
        if (j != 0 && grid[i][j - 1] == 1)
        {
            q.push({i, j - 1});
            grid[i][j - 1] = 2;
        }
        if (j != c - 1 && grid[i][j + 1] == 1)
        {
            q.push({i, j + 1});
            grid[i][j + 1] = 2;
        }
    }

    if (allrotten(grid))
        return minute;
    else
        return -1;
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, -1));
    int r = ans.size();
    int c = ans[0].size();
    int i = 0;
    int j = 0;
    int numend = n * n;
    int num = 1;
    int dir = 1; // right 1  -- up 4
    while (num <= numend)
    {
        ans[i][j] = num;
        num++;
        if (dir == 1)
        {
            if (j == c - 1 || ans[i][j + 1] != -1)
            {
                dir = dir % 4 + 1;
                i++;
                continue;
            }
            j++;
            continue;
        }
        if (dir == 2)
        {
            if (i == r - 1 || ans[i + 1][j] != -1)
            {
                dir = dir % 4 + 1;
                j--;
                continue;
            }
            i++;
            continue;
        }
        if (dir == 3)
        {
            if (j == 0 || ans[i][j - 1] != -1)
            {
                dir = dir % 4 + 1;
                i--;
                continue;
            }
            j--;
            continue;
        }
        if (dir == 4)
        {
            if (i == 0 || ans[i - 1][j] != -1)
            {
                dir = dir % 4 + 1;
                j++;
                continue;
            }
            i--;
            continue;
        }
    }
    return ans;
}
