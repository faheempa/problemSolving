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
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            int one_step = dp[i - 1];
            int two_step = dp[i - 2];
            dp[i] = one_step + two_step;
        }
        return dp[n];
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
