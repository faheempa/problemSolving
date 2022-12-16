// quesion
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4332/0000000000941e56

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

