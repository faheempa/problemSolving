// Question
// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
}

string solve(vector<string> &s)
{
    int ans = s[0].length(), n = s.size();
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (j < s[i].length() && s[i][j] == s[0][j])
            j++;
        ans = min(ans, j);
    }
    return s[0].substr(0, ans);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> words;
        read_string_vector(words);
        cout << "Case #" << i << ": ";
        cout << solve(words);
        cout << endl;
    }
}
