// question
// https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

double help(double x, int n)
{
    if (n == 0)
        return 1;
    if (x == 0)
        return 0;

    double res = help(x, n / 2);
    res = res * res;
    if (n % 2 == 0)
        return res;
    return res * x;
}
double solve(double x, int n)
{
    double result = help(x, n);
    if (n < 0)
        return 1 / result;
    return result;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        double x;
        int n;
        cin >> x >> n;

        cout << "Case #" << i << ": ";
        cout << solve(x, n);
        cout << endl;
    }
}