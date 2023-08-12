// question
// https://leetcode.com/problems/word-pattern/

#include <bits/stdc++.h>
using namespace std;

bool solve(string pattern, string s)
{
    stringstream str(s);
    string word;
    int i = 0;
    unordered_map<char, string> mp1;
    unordered_map<string, bool> mp2;
    while (str >> word)
    {
        char p = pattern[i++];
        if (mp1.find(p) == mp1.end())
        {
            if (mp2.find(word) != mp2.end())
                return false;
            mp1[p] = word;
            mp2[word] = true;
        }
        else
        {
            if (mp1[p] != word or mp2[word] != true)
                return false;
        }
    }
    return i == pattern.length();
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string pattern, s;
        cin >> pattern;
        cin.ignore();
        getline(cin, s);

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(pattern, s);
        cout << endl;
    }
}