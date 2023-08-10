// question
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

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
    int profit{0};
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        vector<int> prices;
        read_int_vector(prices);

        cout << "Case #" << i << ": ";
        cout << solve(prices);
        cout << endl;
    }
}