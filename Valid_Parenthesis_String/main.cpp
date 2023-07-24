// question
// https://leetcode.com/problems/valid-parenthesis-string/description/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    int leftMin{0}, leftMax{0};
    for (auto &c : s)
    {
        if (c == '(')
            leftMin++, leftMax++;
        else if (c == ')')
            leftMin--, leftMax--;
        else
            leftMin--, leftMax++;
        if (leftMin < 0)
            leftMin = 0;
        if (leftMax < 0)
            return false;
    }
    return leftMin == 0;
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
        cout << boolalpha << solve(s);
        cout << endl;
    }
}