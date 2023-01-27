// Question

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

class Problem
{
private:
    vector<int> nums;
    int target;
    pair<int, int> ans;

public:
    Problem()
    {
        ans = pair(-1, -1);
    }
    void input()
    {
        read_int_vector(nums);
        cin >> target;
    }
    void solve()
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums.at(i)) > 0)
            {
                ans = pair(mp.at(nums.at(i)), i);
                return;
            }
            mp[target - nums.at(i)] = i;
        }
    }
    void output()
    {
        cout << ans.first << " " << ans.second;
    }
};

int main()
{
    // testing multiple inputs
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Problem obj = Problem();
        obj.input();
        obj.solve();
        cout << "Case #" << i << ": ";
        obj.output();
        cout << endl;
    }
}
