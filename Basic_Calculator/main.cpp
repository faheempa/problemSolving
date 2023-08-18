// question
// https://leetcode.com/problems/basic-calculator/

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    stack<int> stk;
    int output{0}, sign{1}, cur{0};

    for (auto &c : s)
    {
        if (isdigit(c))
        {
            cur = cur * 10 + (c - '0');
        }
        else if (c == '+' or c == '-')
        {
            output += cur * sign;
            if (c == '+')
                sign = 1;
            else
                sign = -1;
            cur = 0;
        }
        else if (c == '(')
        {
            stk.push(output);
            stk.push(sign);
            output = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            output += cur * sign;
            output *= stk.top();
            stk.pop();
            output += stk.top();
            stk.pop();
            cur = 0;
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