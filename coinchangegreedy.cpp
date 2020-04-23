#include <iostream>
#include <algorithm>

using namespace std;

int coinchange(int *a, int n, int money)
{
    int count = 0;
    while (money)
    {
        int *it = upper_bound(a, a + n, money);
        it--;
        money -= *it;
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int s = sizeof(arr) / sizeof(int);
    cout << coinchange(arr, s, n);
    return 0;
}