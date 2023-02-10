// Question
// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;

int next(int k)
{
    int sum = 0;
    while (k > 0)
    {
        int temp = k % 10;
        sum += temp * temp;
        k /= 10;
    }
    return sum;
}

bool solve(int n)
{
    vector<int> loop = {4, 16, 20, 37, 42, 58, 89, 145};
    while (true)
    {
        if (n == 1)
            return true;
        if (binary_search(loop.begin(), loop.end(), n))
            return false;
        n = next(n);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a;
        cin >> a;
        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(a);
        cout << endl;
    }
}
