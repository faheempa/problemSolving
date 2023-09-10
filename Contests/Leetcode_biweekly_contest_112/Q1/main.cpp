// question
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    vector<int> odd(26, 0), even(26, 0);
    for (int i = 0; i < 4; i += 2)
    {
        even[s1[i] - 'a']++;
        odd[s1[i + 1] - 'a']++;
        even[s2[i] - 'a']--;
        odd[s2[i + 1] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (even[i] or odd[i])
            return false;
    }
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

        cout << boolalpha;
        cout << "Case #" << i << ": ";
        cout << solve(s1, s2);
        cout << endl;
    }
}