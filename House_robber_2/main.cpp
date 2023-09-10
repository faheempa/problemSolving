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

int rob(vector<int> &arr, int start, int end)
{
    if (start == end)
        return arr[start];

    int n = arr.size();
    vector<int> dp(n, -1);
    dp[start] = arr[start];
    dp[start + 1] = max(arr[start], arr[start + 1]);
    for (int i = start + 2; i <= end; i++)
    {
        int pick = arr.at(i) + dp[i - 2];
        int notPick = dp[i - 1];
        dp.at(i) = std::max(pick, notPick);
    }
    return dp[end];
}
int solve(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    int a = rob(nums, 0, n - 2);
    int b = rob(nums, 1, n - 1);
    return max(a, b);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> vec;
        read_int_vector(vec);

        cout << "Case #" << i << ": ";
        cout << solve(vec);
        cout << endl;
    }
}
