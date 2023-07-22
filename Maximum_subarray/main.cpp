// question
//  https://leetcode.com/problems/maximum-subarray/

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

int solve(vector<int> &vec)
{
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (sum < 0)
            sum = 0;
        sum += vec[i];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> vec;
        read_int_vector(vec);

        cout << "Case #" << i << ": ";
        cout << solve(vec);
        cout << endl;
    }
}