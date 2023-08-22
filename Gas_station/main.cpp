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
    int size=gas.size();
    int curGas{0}, start{0}, gasNeed{0};
    for(int i=0; i<size; i++)
    {
        curGas += gas[i] - cost[i];
        if(curGas<0)
        {
            gasNeed += abs(curGas);
            curGas=0;
            start=i+1;
        }
    }
    return (curGas >= gasNeed)? start : -1;
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