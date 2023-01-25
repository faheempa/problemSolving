// Question
// from the given list of values, find the number of triplets those sum is 0
// eg: -2 4 -1 3 -3
// output: 1 (that is {0,-3,3})

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define e "\n"
#define vi vector<int>
#define vll vector<long long>
#define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define pqr priority_queue<int>
#define pqll priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define pqllr priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define um(a, b) unordered_map<a, b>
#define print(a) for (auto var : a) cout << var << " "
#define sz(a) int(a.size())
#define len(a) int(a.lenght())
const long double PI = 3.141592653589793;
class Timer
{
    std::chrono::_V2::system_clock::time_point start, end;

public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "\nRun time: " << std::fixed << std::setprecision(3) << float(duration.count()) / 1000 << " ms"
                  << "\n";
    }
};
void read_int_vector(vi &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}
void read_int_vector(vi &vec, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}



class Problem
{
private:
    vi numbers;
    int n;
    int ans;

public:
    Problem()
    {
        ans = 0;
    }
    void input()
    {
        read_int_vector(numbers);
        n = numbers.size();
    }
    void solve()
    {
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < n && numbers.at(i) < 0; i++)
        {
            int target = 0 - numbers.at(i);
            for (int j = i + 1; j < n - 1 && numbers.at(j) < target; j++)
                if (binary_search(numbers.begin() + j + 1, numbers.end(), target - numbers.at(j)) == true)
                    ans++;
        }
    }

    void output()
    {
        cout << ans;
    }
};

int main()
{
    // runtime counter
    Timer runtime = Timer();

    // testing multiple inputs
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        Problem obj = Problem();
        obj.input();
        obj.solve();
        cout << "Case #" << i << ": ";
        obj.output();
        cout << e;
    }
}
