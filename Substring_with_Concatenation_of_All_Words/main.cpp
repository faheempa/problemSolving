// question
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

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
    istringstream is(input);
    while (is >> word)
        vec.push_back(word);
}

vector<int> solve(string s, vector<string> &words)
{
    vector<int> result;
    if (words.empty())
        return result;
    unordered_map<string, int> counts, record;
    for (string word : words)
    {
        counts[word]++;
    }
    int len = words[0].size(), num = words.size(), sl = s.size();
    for (int i = 0; i < len; ++i)
    {
        int left = i, sum = 0;
        record.clear();
        for (int j = i; j <= sl - len; j += len)
        {
            string word = s.substr(j, len);
            if (counts.count(word))
            {
                record[word]++;
                sum++;
                while (record[word] > counts[word])
                {
                    // remove the most left word
                    record[s.substr(left, len)]--;
                    left += len;
                    sum--;
                }
                if (sum == num)
                    result.push_back(left);
            }
            else
            {
                record.clear();
                sum = 0;
                left = j + len;
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> words;
        string s;
        cin >> s;
        read_string_vector(words);
        cout << "Case #" << i << ": ";
        print(solve(s, words));
        cout << endl;
    }
}