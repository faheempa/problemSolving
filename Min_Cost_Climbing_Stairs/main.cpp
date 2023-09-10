// Question
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

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
    int solve(vector<int> &cost)
    {
        int size = cost.size();
        vector<int> dp(size, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < size; i++)
        {
            int startFromOne = cost[i] + dp[i - 1];
            int startFromZero = cost[i] + dp[i - 2];
            dp[i] = min(startFromZero, startFromOne);
        }
        return min(dp[size - 1], dp[size - 2]);
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
