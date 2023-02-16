// Question
// https://leetcode.com/problems/3sum/description/

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

vector<vector<int>> solve (vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 and nums.at(i) == nums.at(i - 1))
            continue;
        if (nums.at(i) > 0)
            break;
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = nums.at(i) + nums.at(l) + nums.at(r);
            if (sum == 0)
            {
                ans.push_back({nums.at(i), nums.at(l), nums.at(r)});
                l++;
                while (nums.at(l - 1) == nums.at(l) and l < r)
                    l++;
            }
            else if (sum > 0)
                r--;
            else
                l++;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        cout << "Case #" << i << ": " << endl;
        auto ans = solve(nums);
        for (const auto &a : ans)
            print(a), cout<<endl;
        cout<<endl;
    }
}
