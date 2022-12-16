// quesion
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47e79

#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
#define max 999
int c = 1;

class state
{
public:
    int basket, note, coins;
    state(int basket = 0, int note = 0, int coins = 0)
        : basket{basket}, note{note}, coins{coins} {}
};

class Problem
{
    int n;

public:
    Problem(int n = 0)
        : n{n} {}

    void solve()
    {
        int ans;
        std::queue<class state> q;
        state obj = state();
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        q.push(obj);
        while (!q.empty())
        {
            obj = q.front();
            if (obj.basket == this->n)
            {
                pq.push(obj.coins);
                if (int(pq.size()) >= this->n)
                {
                    ans = pq.top();
                    break;
                }
            }
            else if(obj.basket<this->n)
            {
                q.push(state(obj.basket + 1, obj.note, obj.coins + 1));
                if (obj.note > 0 and obj.note < this->n/2)
                    q.push(state(obj.basket + obj.note, obj.note, obj.coins + 2));
                if (obj.note != obj.basket)
                    q.push(state(obj.basket, obj.basket, obj.coins + 4));
            }
            q.pop();
        }
        cout << ans;
    }
};

int main()
{
    int a, n;
    vector<class Problem> cases;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        Problem obj = Problem(n);
        cases.push_back(obj);
    }
    for (int i = 0; i < a; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).solve();
        cout << endl;
    }
    return 0;
}
