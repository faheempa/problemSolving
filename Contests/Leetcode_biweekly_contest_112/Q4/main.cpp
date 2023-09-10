// question
// https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/

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

long long solve(vector<int> &nums, int m1, int k)
{
    map<long long, long long> m;
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        m[nums[i]]++;
        sum += nums[i];
    }
    if (m.size() >= m1)
    {
        ans = sum;
    }
    for (int i = k; i < nums.size(); i++)
    {
        m[nums[i]]++;
        m[nums[i - k]]--;
        sum += nums[i];
        sum -= nums[i - k];
        if (m[nums[i - k]] == 0)
        {
            m.erase(nums[i - k]);
        }
        if (m.size() >= m1)
        {
            ans = max(ans, sum);
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
        int m, k;
        cin >> m >> k;
        cout << "Case #" << i << ": ";
        cout << solve(nums, m, k);
        cout << endl;
    }
}
