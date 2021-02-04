#include <bits/stdc++.h>

using namespace std;

int main()
{
    string payload = "";
    int counter = 100;
    for(int i = 0;i <= 35 ;i++)
    {
        payload = createstr("A",counter);
        counter += 200;
    }
    return 0;
}