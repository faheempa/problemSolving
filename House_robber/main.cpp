// Question
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

class Solution
{
public:
    int solve(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return arr[0];

        vector<int> dp(n, -1);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            int pick = arr.at(i) + dp[i - 2];
            int notPick = dp[i - 1];
            dp.at(i) = std::max(pick, notPick);
        }
        return dp[n - 1];
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> vec;
        read_int_vector(vec);

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(vec);
        cout << endl;
    }
}
