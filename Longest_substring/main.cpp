// Question
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

string solve(string str)
{
    int left = 0;
    pair<int, int> ans{0, 0}; // starting of substring, no of elements
    vector<bool> map(26, false);
    for (int right = 0; right < str.length(); right++)
    {
        while (map[str[right] - 'a'])
            map[str[left++] - 'a'] = false;

        map[str[right] - 'a'] = true;


        if (ans.second < right - left + 1)
            ans.second = right - left + 1, ans.first=left;
    }
    return str.substr(ans.first, ans.second);
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
