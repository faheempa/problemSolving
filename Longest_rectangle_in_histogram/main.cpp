// Question
// https://leetcode.com/problems/largest-rectangle-in-histogram/

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

int solve(vector<int> &heights)
{
    // [idex, height]
    int res{INT_MIN};
    stack<pair<int, int>> stk;
    for (int i = 0; i < heights.size(); i++)
    {
        int start{i};
        while (stk.empty() == false and stk.top().second > heights[i])
        {
            int index = stk.top().first;
            int height = stk.top().second;
            int width = i - index;
            stk.pop();

            res = max(res, height * width);
            start = index;
        }
        stk.push({start, heights[i]});
    }
    while (stk.empty() == false)
    {
        int height = stk.top().second;
        int width = heights.size() - stk.top().first;
        stk.pop();

        res = max(res, height * width);
    }
    return res;
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
