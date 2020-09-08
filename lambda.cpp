#include <iostream>
#include "conio.hpp"
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 4, 4, 4, 7, 9};
    string c, b;
    c = "eat an apple a day";
    b = "apple";
    int n = c.find(b);
    c.erase(n,b.length() + 1);
    cout << c;
    return 0;
}