#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class H_index
{
    int n, index;
    vector<int> citations;

public:
    H_index(int n = 0, int index = 0)
        : n{n}, index{index} {}
    void read_citations()
    {
        int item;
        for (int i = 0; i < this->n; i++)
        {
            cin >> item;
            this->citations.push_back(item);
        }
    }
    void solve()
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for (int i = 0; i < this->n; i++)
        {
            if (this->citations.at(i) > this->index)
                q.push(citations.at(i));
            if (int(q.size()) > this->index)
            {
                this->index++;
                while (int(q.top()) == this->index and !q.empty())
                    q.pop();
            }
            cout << this->index << " ";
        }
        cout << endl;
    }
};

int main()
{
    int a, n;
    vector<class H_index> cases;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        H_index obj = H_index(n);
        obj.read_citations();
        cases.push_back(obj);
    }
    for (int i = 0; i < a; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).solve();
    }
    return 0;
}

// input
// 2
// 3
// 5 1 2
// 6
// 1 3 3 2 2 15

// output
// Case #1: 1 1 2
// Case #2: 1 1 2 2 2 3

// sample input of 25
// 1 3 2 5 8 10 2 5 1 7 2 4 90 2 4 6 3 8 24 4 23 65 12 76 222
// sample input of 50
//  1 3 2 5 8 10 2 5 1 7 2 4 90 2 4 6 3 8 24 4 23 65 12 76 222 3 12 45 2 34 10 14 16 9 5 20 23 4 2 53 4 32 43 43 2 1 54 23 7 24 50
