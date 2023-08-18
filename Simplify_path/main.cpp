// question
// https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;

string solve(string path)
{
    stack<string> s;
    string res;

    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
            continue;

        string name;
        while (i < path.length() and path[i] != '/')
            name += path[i++];

        if (name == ".")
            continue;

        if (name == "..")
        {
            if (!s.empty())
                s.pop();
        }
        else
        {
            s.push(name);
        }
    }
    while (!s.empty())
    {
        res = '/' + s.top() + res;
        s.pop();
    }
    return (res.length() == 0) ? "/" : res;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string path;
        cin >> path;

        cout << "Case #" << i << ": ";
        cout << solve(path);
        cout << endl;
    }
}