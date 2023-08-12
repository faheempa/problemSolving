// question
// https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int n = s.size();
    int i{0}, j{0};
    int start, end;
    while (i < n)
    {
        while (i < n and isspace(s[i]))
            i++;
        start = j;
        while (i < n and !isspace(s[i]))
        {
            s[j] = s[i];
            j++;
            i++;
            end = j;
        }
        s[j++] = ' ';
        reverse(s.begin() + start, s.begin() + end);
    }
    s.resize(end);
    reverse(s.begin(), s.end());
    return s;
}

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++)
    {
        string s;
        getline(cin, s);
        cout << "Case #" << i << ": ";
        cout << solve(s);
        cout << endl;
    }
}