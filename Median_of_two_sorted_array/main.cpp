// Question
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

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
    double solve(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
        {
            return solve(nums2, nums1);
        }

        int total = m + n;
        int half = (total + 1) / 2;
        int low = 0;
        int high = m;

        while (true)
        {
            // nums1
            int i = (high + low) / 2;
            // nums2
            int j = half - i;

            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;

            // partition is correct
            if (left1 <= right2 && left2 <= right1)
            {
                if (total % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
                break;
            }
            else if (left1 > right2)
                high = i - 1;
            else
                low = i + 1;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> num1, num2;
        read_int_vector(num1);
        read_int_vector(num2);

        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(num1, num2);
        cout << endl;
    }
}
