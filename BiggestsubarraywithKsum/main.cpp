// question
// [25, 10, 5, 3, 1, 1, 2, 3, 7, 3]
// k = 15
// return the size of biggest subarray that add upto k
// 6

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define qi queue<int>
#define qll queue<ll>

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
    vector<int> vec;
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
    vi numbers;
    int k;
    int ans;

public:
    Problem()
    {
        ans = 0;
    }
    void read_input()
    {
        numbers = read_an_int_vector();
        cin >> k;
    }
    void solve()
    {
        int i = 0, sum = 0, n = numbers.size();
        queue<int> Q;
        Q.push(numbers.at(i));
        sum += numbers.at(i++);
        while (!Q.empty())
        {
            if (Q.front() > k and i < n)
            {
                while (!Q.empty())
                    Q.pop();
                sum = 0;
                Q.push(numbers.at(i));
                sum += numbers.at(i++);
                continue;
            }
            if (sum < k and i < n)
            {
                Q.push(numbers.at(i));
                sum += numbers.at(i++);
            }
            else if (sum == k)
            {
                if (ans < int(Q.size()))
                    ans = Q.size();
                sum -= Q.front();
                Q.pop();
                if (Q.empty())
                {
                    Q.push(numbers.at(i));
                    sum += numbers.at(i++);
                }
            }
            else
            {
                sum -= Q.front();
                Q.pop();
            }
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
