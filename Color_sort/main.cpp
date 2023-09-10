// question
// https://leetcode.com/problems/sort-colors/description/

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

class Solution {
public:
    void solve(vector<int>& nums) {
        int mp[]{0,0,0};
        for(auto &a: nums) mp[a]++;
        int i=0;
        for(int j=0; j<3; j++)
            while(mp[j]-->0)
                nums[i++]=j;
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
        cout << "Case #" << i << ": ";
        Solution().solve(nums);
        print(nums);
        cout << endl;
    }
}