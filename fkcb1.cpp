#include <bits/stdc++.h>

using namespace std;

void solve(bitset<9> a)
{
    vector<int> ans(9);
    ans[0] = 1;
    int maxc = 1;
    for (int i = 1; i <= 8; i++)
    {
        if (a[i - 1] == 0)
        {
            for (int j = i; j <= 8; j++)
            {
                if (a[j] == 0)
                {
                    int count = maxc + (j - i) + 1;
                    maxc = count;
                    i--;
                    for (int k = i; k < j; k++)
                    {
                        i++;
                        ans[i] = count;
                        count--;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
        cout << ans[i];
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        bitset<9> bit;
        bit.reset();
        for (int i = 0; i < a.size(); i++)
        {
            if ((a[i] - '0') & 1)
                bit[i] = 1;
            else
                bit[i] = 0;
        }
        solve(bit);
        cout << "\n";
    }
    return 0;
}