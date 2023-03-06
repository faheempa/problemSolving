// Question
// https://leetcode.com/problems/trapping-rain-water/

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

int solve(vector<int> &height)
{
    int left = 0, right = height.size() - 1, ans = 0, left_max = 0, right_max = 0;
    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= left_max)
                left_max = height[left++];
            else
                ans += (left_max - height[left++]);
        }
        else
        {
            if (height[right] >= right_max)
                right_max = height[right--];
            else
                ans += (right_max - height[right--]);
        }
    }
    return ans;
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
