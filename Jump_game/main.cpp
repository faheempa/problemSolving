// question
// https://leetcode.com/problems/jump-game-ii/

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
    int l = 0, r = 0, n = 0, far = 0;
    while (r < nums.size() - 1)
    {
        far = 0;
        while (l <= r)
        {
            far = std::max(l + nums.at(l), far);
            ;
            l++;
        }
        l = r + 1;
        r = far;
        n++;
    }
    return n;
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