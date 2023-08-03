// question
// https://leetcode.com/problems/sum-of-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

// int solve(int a, int b)
// {
//     if(b==0)
//         return a;

//     int carry = (a&b)<<1;
//     int sum =a^b;

//     return getSum(sum, carry);
// }
int solve(int a, int b)
{
    while (b != 0)
    {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << "Case #" << i << ": ";
        cout << solve(a, b);
        cout << endl;
    }
}