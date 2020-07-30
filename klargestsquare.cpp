#include <bits/stdc++.h>

using namespace std;
const int MAX = 100;
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))

int main()
{
    int matrix[][MAX] = {{1, 0, 1, 0, 0},
                         {1, 0, 1, 1, 1},
                         {1, 1, 1, 1, 1},
                         {1, 0, 0, 1, 0}};
    int K = 9, Q = 1;

    int ci = 2, cj = 3;
    int r = 4, c = 5;
    int maxgo = min4(ci - 0, r - ci - 1, cj - 0, c - 1 - cj);
    int dp[100];
    dp[0] = 0;
    dp[1] = 0;
    if (matrix[ci][cj] == 1)
    {
        dp[1] = 1;
    }
    int cur = 1;
    pair<int, int> ul, ur, bl, br;
    ul = ur = bl = br = {ci, cj};
    for (int i = 0; i < maxgo; i++)
    {
        cur++;
        dp[cur] = dp[cur - 1];
        ul = {ul.first - 1, ul.second - 1};
        ur = {ur.first - 1, ur.second + 1};
        bl = {bl.first + 1, bl.second - 1};
        br = {br.first + 1, br.second + 1};
        for (int i = ul.second; i <= ur.second; i++)
        {
            if (matrix[ul.first][i] == 1)
            {
                dp[cur]++;
            }
            if (matrix[bl.first][i] == 1)
            {
                dp[cur]++;
            }
        }
        for (int i = ul.first + 1; i <= bl.first - 1; i++)
        {
            if(matrix[i][ul.second] == 1)
            {
                dp[cur]++;
            }
            if(matrix[i][ur.first] == 1)
            {
                dp[cur]++;
            }
        }
    }
    cout << dp[cur];
    return 0;
}