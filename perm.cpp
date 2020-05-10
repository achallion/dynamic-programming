#include <bits/stdc++.h>

using namespace std;

void genperm(int arr[], int n)
{
    static vector<bool> chosen(n + 1);
    static vector<int> v;
    // base
    if (v.size() == n)
    {
        for (int a : v)
        {
            cout << a;
        }
        cout << "\n";
    }
    // rec
    for (int i = 0; i < n; i++)
    {
        if (!chosen[i])
        {
            chosen[i] = true;
            v.push_back(arr[i]);
            genperm(arr, n);
            v.pop_back();
            chosen[i] = false;
        }
    }
}

int main()
{
    int arr[3] = {1, 2, 3};
    int n = 3;
    vector<int> v;
    genperm(arr, n);
    return 0;
}