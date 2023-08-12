// question
// https://leetcode.com/problems/contains-duplicate-ii/description

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

bool solve(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            if ((i - mp[nums[i]]) <= k)
                return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        int k;
        cin >> k;

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(nums, k);
        cout << endl;
    }
}