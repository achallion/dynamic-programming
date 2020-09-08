#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mina;

int solve(vector<int> a, int s, int e)
{
    
    //  base
    

    //  rec
    int x, y, minsmoke = 1e9+7;
    for (int i = s + 1; i <= e; i++)
    {                                                                                                
        x = solve(a, s, i - 1);
        y = solve(a, i, e);
        minsmoke = min(x * y, minsmoke);
    }
    mina = minsmoke;
    return ((x + y) % 100);
}

int main()
{
    vector<int> a;
    int n;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    cout << solve(a, 0, a.size() - 1);
    return 0;
}