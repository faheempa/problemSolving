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
    stack<pair<int, int>> stk;
    int result = 0;

    for (int i = 0; i < heights.size(); i++)
    {
        int start = i;

        while (!stk.empty() && stk.top().second > heights[i])
        {
            int index = stk.top().first;
            int width = i - index;
            int height = stk.top().second;
            stk.pop();

            result = max(result, height * width);
            start = index;
        }

        stk.push({start, heights[i]});
    }

    while (!stk.empty())
    {
        int width = heights.size() - stk.top().first;
        int height = stk.top().second;
        stk.pop();

        result = max(result, height * width);
    }

    return result;
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
