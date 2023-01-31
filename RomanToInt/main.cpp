// Question
// https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

int solve(string roman)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans{0};
    for (int i = 0; i < roman.length(); i++)
    {
        if (mp[roman[i]] < mp[roman[i + 1]])
            ans -= mp[roman[i]];
        else
            ans += mp[roman[i]];
    }
    return ans;
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
