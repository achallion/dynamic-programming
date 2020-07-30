#include <bits/stdc++.h>

using namespace std;

bool isthere(string &s, char c)
{
    // find c and erase
    auto end = s.end();
    for (auto ptr = s.begin(); ptr != end; ptr++)
    {
        if (*ptr == c)
        {
            s.erase(ptr);
            return true;
        }
    }
    return false;
}

vector<string> commonChars(vector<string> &A)
{
    if (A.size() == 0)
        return vector<string>();
    if (A.size() == 1)
    {
        vector<string> v;
        string s;
        for (char c : A[0])
        {
            s = "";
            s.push_back(c);
            v.push_back(s);
        }
    }
    string help;
    vector<string> ans;
    string s = A[0];
    for (char c : s)
    {
        bool thereis = true;
        for (int i = 1; i < A.size(); i++)
        {
            if (!isthere(A[i], c))
            {
                thereis = false;
                break;
            }
        }
        if (thereis)
        {
            help = "";
            help.push_back(c);
            ans.push_back(help);
        }
    }
    return ans;
}

int balancedStringSplit(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    stack<char> st;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            if (st.top() == 'L')
            {
                st.pop();
                if (st.size() == 0)
                {
                    count++;
                }
                continue;
            }
            st.push('R');
        }
        if (s[i] == 'L')
        {
            if (st.top() == 'R')
            {
                st.pop();
                if (st.size() == 0)
                {
                    count++;
                }
                continue;
            }
            st.push('L');
        }
    }
    return count;
}