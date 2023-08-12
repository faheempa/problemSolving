// question
// https://leetcode.com/problems/isomorphic-strings/description

#include <bits/stdc++.h>
using namespace std;

bool solve(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }

    unordered_map<char, char> mapping;
    unordered_map<char, bool> mappedTo;

    for (int i = 0; i < s.length(); i++)
    {
        char a = s[i], b = t[i];
        if (mapping.find(a) == mapping.end())
        {
            if (mappedTo.find(b) != mappedTo.end())
            {
                return false;
            }
            mapping[a] = b;
            mappedTo[b] = true;
        }
        else
        {
            if (mapping[a] != b)
            {
                return false;
            }
        }
    }

    return true;
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