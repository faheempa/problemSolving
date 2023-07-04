// Question
// https://leetcode.com/problems/house-robber-ii/description/

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
    int n;

public:
    int solve(vector<int> &nums)
    {
        n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int a = rob1(nums, 0, n - 2);
        int b = rob1(nums, 1, n - 1);
        return max(a, b);
    }
    int rob1(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return arr[start];
        vector<int> dp(n, -1);
        int prev2 = arr[start];
        int prev1 = std::max(arr[start + 1], arr[start]);
        for (int i = start + 2; i <= end; i++)
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
