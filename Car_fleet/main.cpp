// Question
// https://leetcode.com/problems/car-fleet/description/

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
#define pll pair<long long, long long>
#define pb push_back
#define eb emplace_back
#define p(a, b) pair<a, b>
#define v(a) vector<a>
#define um(a, b) unordered_map<a, b>
#define sz(a) int(a.size())
#define len(a) int(a.length())
#define deb(a) cout << #a << " " << a << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
const long double PI = 3.141592653589793;
template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
template <class T>
void read_vector(vector<T> &vec, int &n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
}
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

int solve(int target, vector<int> &pos, vector<int> &speed)
{
    map<int, double> m;
    int res = 0;
    double cur = 0;

    for (int i = 0; i < pos.size(); i++)
        m[-pos[i]] = (double)(target - pos[i]) / speed[i];

    for (auto it : m)
        if (it.second > cur)
            cur = it.second, res++;

    return res;
}

int main()
{
    // runtime counter
    Timer runtime = Timer();

    // testing multiple inputs
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> position, speed;
        read_int_vector(position);
        read_int_vector(speed);
        cout << "Case #" << i << ": ";
        cout << solve(n, position, speed);
        cout << endl;
    }
}
