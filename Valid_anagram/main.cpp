// Question
// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t)
{
    if (s.length() != t.length())
        return false;
    vector<int> map(26, 0);
    for (int i = 0; i < s.length(); i++)
        map[s[i] - 'a']++, map[t[i] - 'a']--;
    for (int &a : map)
        if (a != 0)
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(s1, s2);
        cout << endl;
    }
}
