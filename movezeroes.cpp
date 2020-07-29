#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = -1;
    int j = 0;
    while (j != nums.size())
    {
        if(nums[j] != 0)
        {
            i++;
            // swap i j
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        j++;
    }
}