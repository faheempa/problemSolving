// Question
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res += middleOut(s, i, i);
        res += middleOut(s, i, i + 1);
    }
    return res;
}
int middleOut(string s, int i, int j)
{
    int count{0};
    while (i >= 0 && j <= s.size() - 1 && s[i] == s[j])
    {
        i--;
        j++;
        count++;
    }
    return count;
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
