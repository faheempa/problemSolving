
// Question
// https://leetcode.com/problems/container-with-most-water/description/

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

int solve(vector<int> &nums)
{
    int l{0}, r = nums.size() - 1;
    int res{0};
    while (l <= r)
    {
        int cur_storage = (r - l) * min(nums[l], nums[r]);
        res = max(res, cur_storage);
        if (nums[l] < nums[r])
            l++;
        else
            r--;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        cout << "Case #" << i << ": ";
        cout << solve(nums);
        cout << endl;
    }
}
