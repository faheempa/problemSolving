// Question
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

vector<int> solve(vector<int> &temps)
{
    int n = temps.size();
    if (n < 2)
        return temps;

    stack<int> s;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and temps[s.top()] < temps[i])
        {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
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
        print(solve(nums));
        cout << endl;
    }
}
