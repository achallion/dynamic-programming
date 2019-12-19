#include <iostream>
#include <vector>

#define array2d vector<vector<int>>
#define array2dinit (size, vector<int>(size, 0))

using namespace std;

array2d multiply(array2d x,array2d y)
{
    int size = x.size();
    int sum = 0;
    array2d ans array2dinit;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum = 0;
            for (int k = 0; k < size; k++)
            {
                sum += (x[i][k] * y[k][j]);
            }
            ans[i][j] = sum;
        }
    }
    return ans;
}

array2d power(array2d x,int p)
{
    // base
    if(p == 1)
    {
        return x;
    }

    int size = x.size();
    array2d ans array2dinit;
    if(p == 0)
    {
        for (int i = 0; i < size; i++)
        {
            ans[i][i] = 1;
        }
        return ans;
    }
    // rec
    x = power(x, (p / 2));
    ans = multiply(x, x);
    if((p & 1) == 1)
    {
        ans = multiply(ans, x);
    }
    return ans;
}

vector<int> vectrev(vector<int> x)
{
    int size = x.size();
    vector<int> ans(x.size());
    for (int i = 0; i < x.size(); i++)
    {
        ans[i] = x[size - i - 1];
    }
    return ans;
}

int main()
{
    int n, steps;
    cin >> n >> steps;
    int size = steps;
    array2d q array2dinit;
    array2d ans array2dinit;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i == 0)
            {
                q[i][j] = 1;
            }
            if(j + 1 == i)
            {
                q[i][j] = 1;
            }
        }
    }
    int k = n + 1 - steps;
    for (int i = 0; i < size; i++)
    {
        ans = power(q, k);
    }
    int sum = 0;
    vector<int> vect;
    vect.push_back(1);
    for (int i = 1; i < size; i++)
    {
        sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += vect[j];
        }
        vect.push_back(sum);
    }
    sum = 0;
    vect = vectrev(vect);
    for (int i = 0; i < size; i++)
    {
        sum += ans[0][i] * vect[i];
    }
    cout << "\n\n"
         << sum;
    return 0;
}