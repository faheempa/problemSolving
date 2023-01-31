// Question
// https://leetcode.com/problems/two-sum/description/

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

vector<int> solve(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums.at(i)) != mp.end())
            return {mp.at(nums.at(i)), i};
        mp[target - nums.at(i)] = i;
    }
    return {-1, -1};
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        int target;
        cin >> target;

        cout << "Case #" << i << ": ";
        print(solve(nums, target));
        cout << endl;
    }
}
