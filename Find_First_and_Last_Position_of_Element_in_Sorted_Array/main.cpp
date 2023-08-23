// question
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

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

pair<int, int> solve(vector<int> &nums, int target, int left, int right)
{
    int beg, end;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            if (mid == right)
                end = mid;
            else if (nums[mid + 1] != target)
                end = mid;
            else
            {
                auto x = solve(nums, target, mid + 1, right);
                end = max(x.first, x.second);
            }

            if (mid == left)
                beg = mid;
            else if (nums[mid - 1] != target)
                beg = mid;
            else
            {
                auto x = solve(nums, target, left, mid - 1);
                beg = min(x.first, x.second);
            }

            return {beg, end};
        }
        if (target <= nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return {-1, -1};
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        int target;
        cin >> target;
        cout << "Case #" << i << ": ";
        auto res = solve(nums, target, 0, nums.size()-1);
        cout << res.first << " " << res.second << endl;
    }
}