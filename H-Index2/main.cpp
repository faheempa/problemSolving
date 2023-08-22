// question
// https://leetcode.com/problems/h-index/description/

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

int solve(vector<int> &cites)
{
    sort(cites.begin(), cites.end());
    int h = cites.size();
    for (int i = 0; i < cites.size(); i++)
    {
        if (cites[i] >= h)
            return h;

        h--;
    }
    return h;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> cites;
        read_int_vector(cites);

        cout << "Case #" << i << ": ";
        cout << solve(cites);
        cout << endl;
    }
}