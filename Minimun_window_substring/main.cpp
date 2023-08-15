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

    int need = t.size(), start = 0, end = 0, winSize = INT_MAX, head = 0;
    while (end < int(s.size()))
    {
        if (map[s[end]] > 0)
            need--;

        map[s[end]]--;

        while (need == 0)
        {
            // update window size
            if (end - start + 1 < winSize)
            {
                winSize = end - start + 1;
                head = start;
            }
            // we need to move start pointer to right
            if (map[s[start]] == 0)
                need++;

            map[s[start]]++;
            start++;
        }
        end++;
    }
    return winSize == INT_MAX ? "" : s.substr(head, winSize);
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
