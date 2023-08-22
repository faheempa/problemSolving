// question
// https://leetcode.com/problems/basic-calculator/

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<pair<int, int>> stk;
    int output{0}, cur{0}, sign{1};
    for (auto &c : s)
    {
        if (isdigit(c) == true)
        {
            cur = cur * 10 + (c - '0');
        }
        else if (c == '+' or c == '-')
        {
            output += cur * sign;
            cur = 0;
            if (c == '+')
                sign = 1;
            else
                sign = -1;
        }
        else if (c == '(')
        {
            stk.push({output, sign});
            output = 0;
            sign=1;
        }
        else if (c == ')')
        {
            output += cur * sign;
            cur=0;
            auto val = stk.top();
            stk.pop();
            output *= val.second;
            output += val.first;
        }
    }
    return output + cur * sign;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;

        cout << "Case #" << i << ": ";
        cout << solve(s);
        cout << endl;
    }
}