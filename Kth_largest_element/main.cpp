// Question
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

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

class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        int n = -1, i = 0, j = nums.size() - 1;
        while (n != k)
        {
            if (n < k)
                i = n + 1;
            else
                j = n - 1;

            n = quick_part(nums, i, j);
        }
        return nums.at(n);
    }
    int quick_part(vector<int> &nums, int i, int j)
    {
        if (i == j)
            return i;

        int pivot = nums.at(j), p = i, q = j;
        while (true)
        {
            while (nums.at(p) < pivot)
                p++;

            if (p == q)
                break;

            std::swap(nums.at(p), nums.at(--q));
        }
        std::swap(nums.at(j), nums.at(q));
        return q;
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
        int k;
        cin >> k;

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(nums, k);
        cout << endl;
    }
}
