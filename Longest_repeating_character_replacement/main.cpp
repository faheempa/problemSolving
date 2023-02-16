// Question
// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <bits/stdc++.h>
using namespace std;

int solve(string str, int k)
{
    unordered_map<char, int> map;
    int majority = 0, l = 0, ans=0;
    for (int r = 0; r < str.size(); r++)
    {
        map[str[r]]++;
        majority = max(majority, map[str[r]]);

        if ((r - l + 1) - majority > k)
            map[str[l++]]--;

        ans=max(ans, r-l+1);
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
        int k;
        cin >> s >> k;
        cout << "Case #" << i << ": ";
        cout << solve(s, k);
        cout << endl;
    }
}
