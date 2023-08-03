// question
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

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
    if (nums.size() < 2)
        return nums.size();

    int l = 0;
    for (int r = 2; r < nums.size(); r++)
    {

        if (nums[r] == nums[l])
            continue;

        nums[l + 2] = nums[r];
        l++;
    }
    return l + 2;
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
        int res = solve(nums);
        for (int i = 0; i < res; i++)
            cout << nums[i] << " ";
        cout << endl;
    }
}