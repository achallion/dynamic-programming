#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int a[] = {4, 7, 4, 3, 9, 4, 4, 6, 4};
    int size = sizeof(a) / sizeof(int);
    sort(a, a + size);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    int mid = floor((float)size / 2);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count += (a[i] == a[mid] ? 1 : 0);
    }

    cout << count << " " << (size / 2) + 1;

    return 0;
}