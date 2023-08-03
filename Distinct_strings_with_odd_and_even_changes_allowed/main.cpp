// question
//  https://www.geeksforgeeks.org/distinct-strings-odd-even-changes-allowed/

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
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

string getHash(string s)
{
    vector<int> evenHash(26, 0);
    vector<int> oddHash(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
            evenHash[s[i] - 'a']++;
        else
            oddHash[s[i] - 'a']++;
    }
    string hash = "";
    for (int i = 0; i < 26; i++)
    {
        hash += to_string(oddHash[i]);
    }
    hash += "#";
    for (int i = 0; i < 26; i++)
    {
        hash += to_string(evenHash[i]);
    }
    return hash;
}

int solve(vector<string> &vec)
{
    unordered_set<string> hashSet;
    for (int i = 0; i < vec.size(); i++)
    {
        hashSet.insert(getHash(vec[i]));
    }
    return hashSet.size();
}


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> vec;
        read_string_vector(vec);

        cout << "Case #" << i << ": ";
        cout << solve(vec);
        cout << endl;
    }
}