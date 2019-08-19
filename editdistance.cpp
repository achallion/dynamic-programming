#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int edit(string input,string output)
{
    int m = input.size();
    int n = output.size();
    int memo[m + 1][n + 1]; // input is represented by column

    // Fill 0th row
    for (int i = 0; i <= n; i++)
    {
        memo[0][i] = i;
    }

    // Fill 0th column
    for (int i = 0; i <= m; i++)
    {
        memo[i][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memo[i][j] = min(memo[i - 1][j - 1], min(memo[i - 1][j], memo[i][j - 1])) + 1;
        }
    }
    return memo[m][n];
}