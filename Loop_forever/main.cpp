// Question
// consider the following algorithm:
// while n > 1 do
//     if n mod 2 = 0:
//         n=n/2
//     else:
//         n=3*n+3
//
// An input number n is given, check whether the number loop forever?
// print yes if it loops forever, else print no.

#include <bits/stdc++.h>
using namespace std;

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

string solve(int n)
{
    if ((n ^ (n - 1) & n ^ n) == false)
        return "no";
    else
        return "yes";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        read(n);
        cout << "Case #" << i << ": ";
        cout << solve(n);
        cout << endl;
    }
}
