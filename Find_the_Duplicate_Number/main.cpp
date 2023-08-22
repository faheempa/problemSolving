// Question
// https://leetcode.com/problems/find-the-duplicate-number/description/

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

int solve(vector<int> &nums)
    {
        int fast{0}, slow{0};
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow)
                break;
        }
        slow = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[fast];
            if (fast == slow)
                return slow;
        }
    }

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);

        cout << "Case #" << i << ": ";
        cout << solve(nums);
        cout << endl;
    }
}
