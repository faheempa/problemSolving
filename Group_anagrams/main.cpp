// Question
// https://leetcode.com/problems/group-anagrams/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
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

string getKey(string str)
{
    vector<int> count(26, 0);
    for (int j = 0; j < str.size(); j++)
        count[str[j] - 'a']++;

    string key;
    for (int i = 0; i < 26; i++)
        if (count[i])
            key += string(count[i], i + 'a');
    return key;
}
vector<vector<string>> solve(vector<string> strs)
{
    unordered_map<string, vector<string>> map;
    for (const auto &str : strs)
        map[getKey(str)].push_back(str);

    vector<vector<string>> ans;
    for (auto it = map.begin(); it != map.end(); it++)
        ans.push_back(it->second);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> s;
        read_string_vector(s);

        cout << "Case #" << i << ": ";
        for (const auto &a : solve(s))
            cout << "[ ", print(a), cout << "] ";
        cout << endl;
    }
}