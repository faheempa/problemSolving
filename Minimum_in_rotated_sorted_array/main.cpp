// Question
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

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
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (nums.at(mid) < nums.at(r))
            r = mid;
        else
            l = mid + 1;
    }
    return nums.at(mid);
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
