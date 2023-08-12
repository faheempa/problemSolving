// question
// https://leetcode.com/problems/length-of-last-word/description/

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int res{0};
    bool done{false};
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (done and s[i] == ' ')
            break;
        if (s[i] == ' ')
            continue;
        done = true;
        res++;
    }
    return res;
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