// Question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caa74/0000000000acf079

#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793;
template <typename... T>
void read(T&... args)
{
    ((cin >> args), ...);
}

long double solve(int r, int a, int b)
{
    long double area = 0;
    bool i = true;
    while (r > 0)
    {
        area += r * r;
        if (i)
            r *= a;
        else
            r /= b;
        i = not i;
    }
    return area *= PI;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i < t; i++)
    {
        int r,a,b;
        read(r,a,b);
        cout << "Case #" << i << ": ";
        cout << std::fixed << std::setprecision(6) << solve(r, a, b);
        cout << endl;
    }
}
