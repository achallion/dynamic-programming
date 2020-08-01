#include <bits/stdc++.h>

using namespace std;

void rec(string &s)
{

    // base
    if (s.begin() == s.end())
    {
        return;
    }

    // rec
    auto ptr = s.begin();
    string remw = "";
    for (; ptr != s.end(); ptr++)
    {
        if (*ptr == ' ')
        {
            break;
        }
        remw.push_back(*ptr);
    }
    if (ptr != s.end())
        s.erase(s.begin(), ptr + 1);
    else
        s.erase(s.begin(), s.end());
    rec(s);
    if (!s.empty())
        s.push_back(' ');

    for (int i = 0; i < remw.size(); i++)
    {
        s.push_back(remw[i]);
    }
}

string reverseWords(string s)
{
    // remove leading and trailing spaces
    auto beg = s.begin();
    auto end = s.end();
    auto ptr = beg;
    while (ptr != end)
    {
        if (*ptr != ' ')
        {
            break;
        }
        ptr++;
    }
    s.erase(beg, ptr);
    ptr = end - 1;
    while (ptr != beg)
    {
        if (*ptr != ' ')
        {
            break;
        }
        ptr++;
    }
    s.erase(ptr + 1, end);

    rec(s);
    return s;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = (r > 0 ? matrix[0].size() : 0);

    int i = 0;
    int j = c - 1;

    while (matrix[i][j] != target)
    {
        if (target > matrix[i][j])
        {
            i++;
            if(i >= r )
            {
                return false;
            }
            continue;
        }
        j--;
        if(j < 0 )
        {
            return false;
        }
    }
    if (matrix[i][j] == target)
        return true;
    return false;
}

int main()
{
    string a = "   i can do better   ";
    cout << reverseWords(a);
    return 0;
}