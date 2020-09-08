#include <iostream>
#include <algorithm>

using namespace std;

int dp(int *a,int n)
{
    int *memo = new int[n];
    int ans;
    memo[0] = 1;
    int maxo;
    for (int i = 1; i < n; i++)
    {
        maxo = memo[0];
        for (int j = 0; j < i; j++)
        {
            if(a[j] <= a[i])
            {
                maxo = max(maxo, memo[j]);
            }
        }
        memo[i] = maxo + 1;
    }
    ans = memo[n - 1];
    delete[] memo;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << dp(a, n);

    delete[] a;
    return 0;
}