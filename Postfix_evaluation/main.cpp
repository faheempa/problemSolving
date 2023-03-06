// Question
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

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

int solve(vector<string> &tokens)
{
    stack<int> stk;
    for (string &c : tokens)
    {
        if (c == "+" || c == "-" || c == "/" || c == "*")
        {
            long a = stk.top();
            stk.pop();
            long b = stk.top();
            stk.pop();
            if (c == "+")
                stk.push(b + a);
            else if (c == "-")
                stk.push(b - a);
            else if (c == "/")
                stk.push(b / a);
            else if (c == "*")
                stk.push(b * a);
        }
        else
        {
            stk.push(stoi(c));
        }
    }
    return stk.top();
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> tokens;
        read_string_vector(tokens);
        cout << "Case #" << i << ": ";
        cout << solve(tokens);
        cout << endl;
    }
}
