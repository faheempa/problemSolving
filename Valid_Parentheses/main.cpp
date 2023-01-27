// question
// https://leetcode.com/problems/valid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

bool solve(string str)
{
    stack<char> list;
    for (auto itr = str.begin(); itr != str.end(); itr++)
    {
        if (*itr == '(' || *itr == '{' || *itr == '[')
            list.push(*itr);
        else if (list.empty() || list.top() == '{' && *itr != '}' || list.top() == '(' && *itr != ')' || list.top() == '[' && *itr != ']')
        {
            return false;
        }
        else
            list.pop();
    }
    return (list.empty() ? true : false);
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << boolalpha << solve(s) << endl;
    }
}
