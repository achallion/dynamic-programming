#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int i = -1;
    int j = 0;
    for (; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    return i;
}