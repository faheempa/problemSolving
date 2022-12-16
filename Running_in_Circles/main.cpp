#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;

class Problem
{
        long long n;
        long long l;
        vector<pair<long long, char>> runs;

public:
        Problem(long long l = 0, long long n = 0)
            : n{n}, l{l} {}
        void read_inputs()
        {
                long long a;
                char b;
                for (long long i = 0; i < this->n; i++)
                {
                        cin >> a >> b;
                        runs.push_back(pair(a, b));
                }
        }
        void solve()
        {
                char clockwise{'C'}, anticlockwise{'A'};
                long long lap = 0, distance = 0;
                char dir = clockwise;
                for (auto run : runs)
                {
                        if (run.second == clockwise)
                        {
                                if (dir == clockwise)
                                        distance += run.first;
                                else
                                {
                                        if (run.first >= distance)
                                        {
                                                distance = run.first - distance;
                                                dir = clockwise;
                                        }
                                        else
                                                distance -= run.first;
                                }
                        }
                        else
                        {
                                if (dir == anticlockwise)
                                        distance += run.first;
                                else
                                {
                                        if (run.first >= distance)
                                        {
                                                distance = run.first - distance;
                                                dir = anticlockwise;
                                        }
                                        else
                                                distance -= run.first;
                                }
                        }
                        if(distance>=this->l)
                        {
                                lap+=distance/this->l;
                                distance%=this->l;
                        }
                }
                cout<<lap<<endl;
        }
};

int main()
{
        long long a, n, l;
        vector<class Problem> cases;
        cin >> a;
        for (long long i = 0; i < a; i++)
        {
                cin >> l >> n;
                Problem obj = Problem(l, n);
                obj.read_inputs();
                cases.push_back(obj);
        }
        for (long long i = 0; i < a; i++)
        {
                cout << "Case #" << i + 1 << ": ";
                cases.at(i).solve();
        }
        return 0;
}


// input
// 3
// 5 3
// 8 C
// 4 A
// 5 C
// 4 5
// 2 C
// 8 A
// 3 A
// 5 C
// 8 A
// 4 3
// 3 C
// 2 A
// 5 C

// output
// Case #1: 1
// Case #2: 5
// Case #3: 1

