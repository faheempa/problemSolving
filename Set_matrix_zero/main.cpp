// Question
// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define e "\n"
#define vi vector<int>
#define vll vector<long long>
#define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define pq_rev priority_queue<int>
#define pql priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define pql_rev priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define um(a, b) unordered_map<a, b>
#define print(a)         \
    for (auto &&var : a) \
    cout << var << " "
#define lenv(a) int(a.size())
#define lens(a) int(a.lenght())
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
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);

class Problem
{
private:
    vector<vi> matrix;

public:
    Problem()
    {
    }
    void input()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            vi a = read_an_int_vector();
            matrix.pb(a);
        }
    }
    void solve()
    {
        int rows = lenv(matrix), cols = lenv(matrix.at(0));
        vector<bool> row_matrix(rows, false), col_matrix(cols, false);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix.at(i).at(j) == 0)
                {
                    row_matrix.at(i) = true;
                    col_matrix.at(j) = true;
                }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (row_matrix.at(i) || col_matrix.at(j))
                    matrix.at(i).at(j) = 0;
    }
    void output()
    {
        for (auto var : matrix)
        {
            cout << e;
            print(var);
        }
    }
};

int main()
{
    // runtime counter
    Timer runtime = Timer();

    // multiple test cases
    int no_of_cases, c = 1;
    cin >> no_of_cases;
    vector<class Problem> problems(no_of_cases);
    for (auto problem : problems)
    {
        problem.input();
        problem.solve();
        cout << "Case #" << c++ << ": ";
        problem.output();
        cout << e;
    }

    // single test case
    // Problem obj = Problem();
    // obj.input();
    // obj.solve();
    // obj.output();
}

// user defined functions
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