// question
// [25, 10, 5, 3, 1, 1, 2, 3, 7, 3]
// k = 15
// return the size of biggest subarray that add upto k
// 6

#include <bits/stdc++.h>
using namespace std;

vector<int> read_an_int_vector()
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_an_int_vector();
    istringstream is(input);
    vector<int> vec((istream_iterator<int>(is)), istream_iterator<int>());
    return vec;
}

int solve(vector<int> nums, int k)
{
    int l{0}, r{0}, sum{0}, res{0};
    while (r < nums.size())
    {
        if (nums[r] > k and r < nums.size())
        {
            r++;
            sum = nums[r];
            l = r;
        }
        else if (sum < k)
        {
            r++;
            sum += nums[r];
        }
        else if (sum == k)
        {
            res = max(res, r - l + 1);
            sum -= nums[l++];
        }
        else
        {
            sum -= nums[l++];
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> numbers;
        int k;
        numbers = read_an_int_vector();
        cin >> k;
        cout << "Case #" << i << ": ";
        cout << solve(numbers, k) << endl;
    }

    return 0;
}
