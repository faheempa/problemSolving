// question
// https://leetcode.com/problems/minimum-size-subarray-sum/

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

int solve(int target, vector<int> &nums)
{
    int i{0}, j{0}, sum{0}, res{INT_MAX};

    while (i < nums.size())
    {
        sum += nums[i];
        while (sum >= target)
        {
            res = std::min(res, i - j + 1);
            sum -= nums[j];
            j++;
        }
        i++;
    }
    return (res == INT_MAX) ? 0 : res;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int target;
        cin >> target;
        vector<int> nums;
        read_int_vector(nums);
        cout << "Case #" << i << ": ";
        cout << solve(target, nums);
        cout << endl;
    }
}