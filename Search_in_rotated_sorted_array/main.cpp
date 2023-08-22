// Question
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

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

int solve(vector<int> &nums, int target)
{
    int left{0}, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        // left side
        if (nums[left] <= nums[mid])
        {
            if (target > nums[mid] or target < nums[left])
                left = mid + 1;
            else 
                right = mid - 1;
        }
        // right side
        else
        {
            if (target < nums[mid] or target > nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        int t;
        read_int_vector(nums);
        cin >> t;
        cout << "Case #" << i << ": ";
        cout << solve(nums, t);
        cout << endl;
    }
}
