// Question
//

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
    if (n == 0)
        return {};
    if (n == 1)
        return {0};

    vector<int> ans(n, 0);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        while (not stk.empty() and temps.at(stk.top()) < temps.at(i))
        {
            ans.at(stk.top()) = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    return ans;
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
