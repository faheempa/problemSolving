// Question
// https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

string solve(string s, string t)
{
    int map[128]{};
    for (auto &c : t)
        map[c]++;
    int count = t.size(), start = 0, end = 0, l = INT_MAX, head = 0;
    while (end < int(s.size()))
    {
        if (map[s[end++]]-- > 0)
            count--;
        while (count == 0)
        {
            if (end - start <= l)
                l = end - (head = start);
            if (map[s[start++]]++ == 0)
                count++;
        }
    }
    return l == INT_MAX ? "" : s.substr(head, l);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s, t;
        read(s, t);
        cout << "Case #" << i << ": ";
        cout << solve(s, t);
        cout << endl;
    }
}
