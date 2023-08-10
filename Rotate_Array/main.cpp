// question
// https://leetcode.com/problems/rotate-array/

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

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums.begin(), nums.begin() + (nums.size() - k));
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int k;
        cin >> k;
        vector<int> nums;
        read_int_vector(nums);
        rotate(nums, k);
        cout << "Case #" << i << ": ";
        print(nums);
        cout << endl;
    }
}