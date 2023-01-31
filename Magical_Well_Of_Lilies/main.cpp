// Question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb1b6/0000000000c47e79

#include <bits/stdc++.h>
using namespace std;

class state
{
public:
    int basket, note, coins;
    state(int basket = 0, int note = 0, int coins = 0)
        : basket{basket}, note{note}, coins{coins} {}
};

int solve(int n)
{
    int ans;
    std::queue<class state> q;
    state obj = state();
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    q.push(obj);
    while (!q.empty())
    {
        obj = q.front();
        if (obj.basket == n)
        {
            pq.push(obj.coins);
            if (int(pq.size()) >= n)
            {
                ans = pq.top();
                break;
            }
        }
        else if (obj.basket < n)
        {
            q.push(state(obj.basket + 1, obj.note, obj.coins + 1));
            if (obj.note > 0 and obj.note < n / 2)
                q.push(state(obj.basket + obj.note, obj.note, obj.coins + 2));
            if (obj.note != obj.basket)
                q.push(state(obj.basket, obj.basket, obj.coins + 4));
        }
        q.pop();
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        cout << "Case #" << i << ": ";
        cout << solve(n);
        cout << endl;
    }
}
