// Question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000941e56

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}

void solve(vector<int> &citations, int n)
{
    int index = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; i++)
    {
        if (citations.at(i) > index)
            q.push(citations.at(i));
        if (int(q.size()) > index)
        {
            index++;
            while (int(q.top()) == index and !q.empty())
                q.pop();
        }
        cout << index << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> citations;
        read_int_vector(citations, n);

        cout << "Case #" << i << ": ";
        solve(citations, n);
        cout << endl;
    }
}
