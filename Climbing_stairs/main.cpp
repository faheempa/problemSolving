// Question
// https://leetcode.com/problems/climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n)
    {
        if (n <= 1)
            return 1;
        int prev1 = 1, prev2 = 1, res;
        for (int i = 2; i <= n; i++)
        {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(n);
        cout << endl;
    }
}
