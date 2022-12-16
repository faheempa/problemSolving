// question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb2e1/0000000000c174f2

#include <bits/stdc++.h>
using namespace std;
#define veci vector<int>
#define vecc vector<char>
#define vecs vector<string>
#define vecf vector<float>
#define ll long long
#define e endl
#define PQ priority_queue<int, std::vector<int>, std::greater<int>>
#define PQ_rev priority_queue<int>
#define PQL priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define PQL_rev priority_queue<long long>

vector<int> read_an_int_vector()
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_an_int_vector();
    istringstream is(input);
    vector<int> vec((istream_iterator<int>(is)), istream_iterator<int>());
    return vec;
}
vector<int> read_an_int_vector(int n)
{
    int a;
    veci vec;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    return vec;
}

class Problem
{
private:
    int m;
    int n;
    int p;
    vector<vector<int>> scoreboard;
    int ans;

public:
    Problem()
    {
        ans = 0;
    }
    void read_input()
    {
        veci temp;
        cin >> m >> n >> p;
        for (int i = 0; i < m; i++)
        {
            temp = read_an_int_vector(n);
            scoreboard.push_back(temp);
        }
    }
    void solve()
    {
        int x, y;
        PQ_rev q;
        for (int i = 0; i < n; i++)
        {
            x = scoreboard[p - 1][i];
            for (int j = 0; j < m; j++)
            {
                if (p + 1 == j)
                    continue;
                if (scoreboard[j][i] > x)
                    q.push(scoreboard[j][i]);
            }
            if (!q.empty())
            {
                y = q.top() - x;
                ans += y;
            }
            while (!q.empty())
                q.pop();
        }
    }
    void print_output()
    {
        cout << ans;
    }
};

int main()
{

    int no_of_cases;
    vector<class Problem> cases;
    cin >> no_of_cases;

    for (int i = 0; i < no_of_cases; i++)
    {
        Problem obj = Problem();
        obj.read_input();
        obj.solve();
        cases.push_back(obj);
    }
    for (int i = 0; i < no_of_cases; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).print_output();
        cout << e;
    }

    return 0;
}
