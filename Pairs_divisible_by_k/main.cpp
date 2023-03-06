// Question
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

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

bool solve(vector<int> &nums, int &k)
{
    if (nums.size() % 2 != 0)
        return false;
        
    vector<int> mp(k, 0);
    for (const int &num : nums)
    {
        int x = num % k;
        x = x < 0 ? x + k : x;
        mp[x]++;
    }

    for (int i = 1; i <= k / 2; i++)
        if (mp[i] != mp[k - i])
            return false;

    return true;
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
