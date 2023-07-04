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
        int prev2 = arr[0];
        int prev1 = std::max(arr[1], arr[0]);
        for (int i = 2; i < n; i++)
        {
            dp.at(i) = std::max(arr.at(i) + prev2, prev1);
            prev2 = prev1;
            prev1 = dp[i];
        }
        return prev1;
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
