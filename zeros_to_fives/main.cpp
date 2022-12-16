#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vf vector<float>
#define vb vector<bool>
#define vll vector<long long>
#define ll long long
#define e endl
#define PQ priority_queue<int, std::vector<int>, std::greater<int>>
#define PQ_rev priority_queue<int>
#define PQL priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define PQL_rev priority_queue<long long>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
const double PI = 3.1415926535897932384626433;

class Problem
{
private:
    ll value;
    string a;
    ll ans;

public:
    Problem()
    {
        ans = 0;
    }
    void read_input()
    {
        cin >> value;
    }
    void solve()
    {
        a = to_string(value);
        int x;
        loop(i,0,int(a.length()))
        {
            if (a[i] == '0')
                x = 5;
            else
                x = a[i] - 48;
            ans = ans * 10 + x;
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

    loop(i,0,no_of_cases)
    {
        Problem obj = Problem();
        obj.read_input();
        obj.solve();
        cases.push_back(obj);
    }
    loop(i,0,no_of_cases)
    {
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).print_output();
        cout << e;
    }

    return 0;
}



