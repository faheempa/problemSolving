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
    // If the list of words is empty, there's nothing to do, so return an empty result.
    // Count how many times each word appears in the list of words.
    // For each starting position in the input string:
        // a. Keep track of a running total of valid words found so far.
        // b. Slide a window to check consecutive groups of words.
        // c. If a group of words matches those in the list:
            // Add one to the count of this group in a record.
            // If the count of the current group exceeds the expected count from the list:
                // Remove the leftmost word from the group and adjust the counts.
                // Move the starting position of the group one word ahead.
            // If the total number of valid words matches the expected total:
                // Record the starting position of the first word in the group.
        // d. If the current group of words doesn't match any from the list:
            // Clear the current tracking record and Reset the count of valid words to zero.
            // Move the starting position of the group to the next word.
    // Collect and return all the recorded starting positions.
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
    int wordLen = words[0].size(), num = words.size(), strLen = s.size();
    for (int i = 0; i < wordLen; ++i)
    {
        int left = i, sum = 0, right = i;
        record.clear();
        while (right <= strLen - wordLen)
        {
            string word = s.substr(right, wordLen);
            right += wordLen;
            if (counts.count(word))
            {
                record[word]++;
                sum++;
                while (record[word] > counts[word])
                {
                    // remove the most left word from the record
                    record[s.substr(left, wordLen)]--;
                    left += wordLen;
                    sum--;
                }
                if (sum == num)
                    result.push_back(left);
            }
            else
            {
                record.clear();
                sum = 0;
                left = right;
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