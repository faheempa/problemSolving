// question
// https://leetcode.com/problems/number-of-1-bits/description/

#include <bits/stdc++.h>
using namespace std;

int solve(uint32_t n)
{
    int res = 0;
    while (n > 0)
    {
        res++;
        n = n & n - 1;
    }
    return res;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        uint32_t n;
        cin >> n;
        cout << "Case #" << i << ": ";
        cout << solve(n);
        cout << endl;
    }
}