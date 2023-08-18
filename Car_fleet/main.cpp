// Question
// https://leetcode.com/problems/car-fleet/description/

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

int solve(int target, vector<int> &pos, vector<int> &speed)
{
    map<int, double, greater<int>> mp;
    for (int i = 0; i < pos.size(); i++)
    {
        mp[pos[i]] = double((target - pos[i])) / speed[i];
    }

    int res{0}, cur = {0};
    for (auto &val : mp)
    {
        if (val.second > cur)
        {
            res++;
            cur = val.second;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> position, speed;
        read_int_vector(position);
        read_int_vector(speed);
        cout << "Case #" << i << ": ";
        cout << solve(n, position, speed);
        cout << endl;
    }
}
