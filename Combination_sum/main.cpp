// Question
// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
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
    int target;
    vector<int> group;
    vector<vector<int>> ans;

public:
    vector<vector<int>> solve(vector<int> &nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        this->target = target;
        help(0, nums, 0);
        return ans;
    }
    void help(int i, vector<int> &nums, int sum)
    {
        if (i == nums.size())
            return;
        if (sum == target)
        {
            ans.push_back(group);
            return;
        }
        if (sum + nums.at(i) > target)
            return;

        group.push_back(nums.at(i));
        help(i, nums, sum + nums.at(i));
        group.pop_back();
        help(i + 1, nums, sum);
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        int k;
        read_int_vector(nums);
        cin >> k;

        Solution sol;
        cout << "Case #" << i << ": ";
        for (const auto &a : sol.solve(nums, k))
        {
            cout << "[ ";
            print(a);
            cout << "]";
        }
        cout << endl;
    }
}
