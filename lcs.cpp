#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int memo[100][100];

void lcs(string a, string b)
{
    // fill base
    int m = a.size();
    int n = b.size();
    for (int i = 0; i <= m; i++)
    {
        memo[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        memo[i][0] = 0;
    }
    

    // follow back
    int q1 = 0, q2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1])
            {
                q1 = memo[i - 1][j - 1] + 1;
            }
            q2 = max(memo[i - 1][j], memo[i][j - 1]);
            memo[i][j] = max(q1, q2);
        }
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    lcs(a, b);
    cout << memo[b.size()][a.size()];
    return 0;
}