// Question
// https://leetcode.com/problems/koko-eating-bananas/

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


class Solution
{
public:
    int solve(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid;
        if (h == piles.size())
            return r;

        int ans = INT_MAX;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (time_took(piles, mid) <= h)
            {
                ans = std::min(ans, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
    int time_took(vector<int> &piles, int speed)
    {
        int time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            time += ceil(piles.at(i) / (float)speed);
        }
        return time;
    }
};

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

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(nums, k);
        cout << endl;
    }
}
