// question
// https://leetcode.com/problems/gas-station/

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

int solve(vector<int> &gas, vector<int> &cost)
{
    int size = gas.size();
    int curGas = 0, extraNeed = 0, start = 0;
    for (int i = 0; i < size; i++)
    {
        curGas += gas[i] - cost[i];
        if (curGas < 0)
        {
            extraNeed += -curGas;
            start = i + 1;
            curGas = 0;
        }
    }
    return (extraNeed > curGas) ? -1 : start;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> gas, cost;
        read_int_vector(gas);
        read_int_vector(cost);

        cout << "Case #" << i << ": ";
        cout << solve(gas, cost);
        cout << endl;
    }
}