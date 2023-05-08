// Question
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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

int solve(vector<int> &prices)
{
    int profit = 0, min = 1e4;
    for (int &x : prices)
        if (x < min)
            min = x;
        else if (x - min > profit)
            profit = x - min;
    return profit;
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

