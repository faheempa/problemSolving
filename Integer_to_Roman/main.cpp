// question
// https://leetcode.com/problems/integer-to-roman/description/

#include <bits/stdc++.h>
using namespace std;

string solve(int num)
{
    string ans;
    vector<pair<int, string>> mp{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    for (auto &p : mp)
    {
        if (num / p.first >= 1)
        {
            for (int i = 0; i < num / p.first; i++)
                ans += p.second;
            num %= p.first;
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int num;
        cin >> num;

        cout << "Case #" << i << ": ";
        cout << solve(num);
        cout << endl;
    }
}