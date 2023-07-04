// Question
// https://leetcode.com/problems/permutations/description/

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
    vector<vector<int>> result;

public:
    vector<vector<int>> solve(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        dfs(nums, 0);

        return result;
    }
    void dfs(vector<int> &nums, int start)
    {
        if (start == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            std::swap(nums.at(start), nums.at(i));
            dfs(nums, start + 1);
            std::swap(nums.at(start), nums.at(i));
        }
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

        Solution sol;
        cout << "Case #" << i << ": ";
        for (const auto &a : sol.solve(nums))
        {
            cout << "[ ";
            print(a);
            cout << "]";
        }
        cout << endl;
    }
}
