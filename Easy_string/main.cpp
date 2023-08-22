// Question
// https://www.codechef.com/ALGQ2023/problems/ALGQ7

#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    bool ans = true;
    unordered_map<char, int> map;
    map['e'] = 0;
    map['a'] = 1;
    map['s'] = 2;
    map['y'] = 3;
    bool condition[]{false, false, false, false};
    for (auto var : s)
    {
        if (map.count(var))
            condition[map[var]] = true;
    }
    for (auto var : condition)
    {
        if (var == false)
            return "NO";
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << solve(s) << endl;
    }
}
