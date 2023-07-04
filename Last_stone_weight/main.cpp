// Question
// https://leetcode.com/problems/last-stone-weight/description/

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
    priority_queue<int> q;

public:
    int solve(vector<int> &stones)
    {
        for (auto &var : stones)
        {
            q.push(var);
        }
        while (q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();

            if (a == b)
                continue;
            else
                q.push(a - b);
        }
        if (q.empty())
            return 0;

        return q.top();
    }
};

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(nums);
        cout << endl;
    }
}
