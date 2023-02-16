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
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[low] <= nums[mid])
            if (nums[low] <= target && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        else if (nums[mid] <= target && target <= nums[high])
            low = mid + 1;
        else
            high = mid - 1;
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
        cin>>t;
        cout << "Case #" << i << ": ";
        cout << solve(nums,t);
        cout << endl;
    }
}
