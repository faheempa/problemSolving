
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
    auto l = nums.begin(), r = nums.end() - 1;
    int ans = -1;
    while (l != r)
    {
        int value = abs(l - r) * min(*l, *r);
        ans = max(ans, value);
        if (*l < *r)
            l++;
        else
            r--;
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
