// Question
// 

#include <bits/stdc++.h>
using namespace std;

bool solve(string str)
{
    int j = str.length() - 1, i = 0;
    while (i <= j)
    {
        while (isalnum(str[i]) == 0)
            i++;
        while (isalnum(str[j]) == 0)
            j--;
        if (toupper(str[i++]) != toupper(str[j--]))
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++)
    {
        string s;
        getline(cin, s);
        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(s);
        cout << endl;
    }
}
