// question
// https://leetcode.com/problems/multiply-strings/description/

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

int val(char n)
{
    return n - '0';
}
string solve(string num1, string num2)
{
    int n = num1.size();
    int m = num2.size();
    string res(m + n, '0');

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int value = val(num1[i]) * val(num2[j]) + val(res[i + j + 1]);
            res[i + j + 1] = value % 10 + '0';
            res[i + j] += value / 10;
        }
    }
    for (int i = 0; i < m + n; i++)
    {
        if (res[i] != '0')
            return res.substr(i);
    }

    return "0";
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string num1, num2;
        cin >> num1 >> num2;

        cout << "Case #" << i << ": ";
        cout << solve(num1, num2);
        cout << endl;
    }
}