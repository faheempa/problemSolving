// question
// https://leetcode.com/problems/hand-of-straights/

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

bool solve(vector<int> &cards, int &n)
{
    int size = cards.size();
    if (size % n != 0)
        return false;

    unordered_map<int, int> count;
    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto &a : cards)
        count[a]++, q.push(a);

    while (not q.empty())
    {
        int min_val = q.top();
        q.pop();
        if (count[min_val]-- < 1)
            continue;
        for (int i = 1; i < n; i++)
            if (count[min_val + i]-- <= 0)
                return false;
    }
    return true;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> cards;
        read_int_vector(cards);
        int n;
        cin >> n;

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(cards, n);
        cout << endl;
    }
}