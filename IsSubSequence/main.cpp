// question
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t)
{
    int i{0}, j{0};
    while (j < t.length() && i < s.length())
    {
        if (t[j] == s[i])
            i++;
        j++;
    }
    return (i == s.length()) ? true : false;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s, t;
        cin >> s >> t;

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(s, t);
        cout << endl;
    }
}