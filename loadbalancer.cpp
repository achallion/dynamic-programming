#include <iostream>

using namespace std;

bool check(int *arr, int n, int avg)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != avg)
        {
            return false;
        }
    }
    return true;
}

double takeavg(int *arr, int l, int r)
{
    double sum;
    for (int i = l; i <= r; i++)
    {
        sum += (double)arr[i];
    }
    float n = r - l + 1;
    return (double)(sum / n);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

pair<double, double> isbalanced(int *arr, int l, int mid, int r)
{
    double lp = 0, rp = 0;
    for (int i = l; i <= mid; i++)
    {
        lp += arr[i];
    }
    for (int i = mid + 1; i <= r; i++)
    {
        rp += arr[i];
    }
    return make_pair(lp, rp);
}

int bs(int *arr, int s, int e, int avg)
{
    // base

    // rec
    int mid = s + e;
    mid /= 2;
    // left is s -> mid
    // right is mid + 1 -> e

    while (!isbalanced(arr, s, mid, e))
    {
    }
}

int count(int *arr, int n)
{
    // we find avg
    int avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += arr[i];
    }

    if (avg % n != 0)
        return -1;

    avg /= n;

    // we find count
    return bs(arr, 0, n - 1, avg);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {16, 17, 15, 0, 20, 1, 1, 2};
    int n = 8;

    cout << count(arr, n);
    return 0;
}