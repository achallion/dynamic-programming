#include <iostream>

using namespace std;

void print2d(int a[5][16],int r,int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int ex(int *a, int k, int n)
{
    // base
    if(n == 0)
    {
        return 1;
    }

    if(n < 0)
    {
        return 0;
    }

    if(k == 0)
    {
        return 0;
    }

    // rec
    int o1 = ex(a, k, n - a[0]);
    int o2 = ex(a + 1, k - 1, n);
    return o1 + o2;
}

int memo[5][16];

void dp(int a[],int n,int price)
{

    // set first row
    for (int i = 0; i <= price; i++)
    {
        memo[0][i] = 0;
        if (i % a[0] == 0)
        {
            memo[0][i] = 1;
        }
    }

    // set first column
    for (int i = 0; i < n; i++)
    {
        memo[i][0] = 1;
    }

    // set other blocks
    int sumabove = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= price; j++)
        {
            sumabove = 0;
            for (int k = 0; k < i; k++)
            {
                sumabove += memo[k][j];
            }
            memo[i][j] = sumabove + memo[i][j - a[i]];
        }
    }
}

int main()
{
    int n, k, a[100];
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    cout << " \n";
    dp(a, k, n);
    cout << memo[k - 1][n];
    return 0;
}