// Question
// https://leetcode.com/problems/subsets/

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
    vector<vector<int>> ans;
    vector<int> subset;

public:
    vector<vector<int>> solve(vector<int> &nums)
    {
        help(0, nums);
        return ans;
    }
    void help(int i, vector<int> &nums)
    {
        if (i == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums.at(i));
        help(i+1, nums);
        subset.pop_back();
        help(i+1, nums);
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
        
        for(const auto &a: sol.solve(nums))
        {
            cout<<"[ ";
            print(a);
            cout<<"]";
        }
        cout << endl;
    }
}
