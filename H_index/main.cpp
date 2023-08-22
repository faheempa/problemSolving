// Question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000941e56

#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

void read_int_vector(vector<int> &vec, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}

vector<int> solve(vector<int> &citations, int n)
{
    vector<int> res;
    int index{0};
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (citations.at(i) > index)
            pq.push(citations.at(i));

        if (int(pq.size()) > index)
        {
            index++;
            while (int(pq.top()) == index and !pq.empty())
                pq.pop();
        }
        res.push_back(index);
    }
    return res;
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
        print(solve(citations, n));
        cout << endl;
    }
}
