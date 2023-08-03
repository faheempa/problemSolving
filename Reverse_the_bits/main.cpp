// question
// https://leetcode.com/problems/reverse-bits/submissions/

#include <bits/stdc++.h>
using namespace std;

uint32_t solve(uint32_t n)
{
    uint32_t res;
    for (int i = 0; i < 32; i++)
    {
        res = (res << 1) | (n & 1);
        n = n >> 1;
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
        uint32_t res = solve(n);
        // print as bits
        for (int i = 31; i >= 0; i--)
        {
            cout << ((res >> i) & 1);
        }
        cout << endl;
    }
}