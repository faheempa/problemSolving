// question
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s1, string s2)
{
    int n = s1.length();
    vector<int> odd(26, 0), even(26, 0);
    for (int i = 0; i < n; i += 2)
    {
        even[s1[i] - 'a']++;
        even[s2[i] - 'a']--;
    }
    for (int i = 1; i < n; i += 2)
    {
        odd[s1[i] - 'a']++;
        odd[s2[i] - 'a']--;
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

        cout << "Case #" << i << ": ";
        cout<<boolalpha;
        cout << solve(s1, s2);
        cout << endl;
    }
}