// question
// https://leetcode.com/problems/find-peak-element/description/

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
    int n = nums.size();
    if (n == 1)
        return 0;

    int low{0}, high{n - 1};
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid > 0 and nums[mid] < nums[mid - 1])
            high = mid - 1;
        else if (mid + 1 < n and nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            return mid;
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
        read_int_vector(nums);
        cout << "Case #" << i << ": ";
        cout << solve(nums);
        cout << endl;
    }
}