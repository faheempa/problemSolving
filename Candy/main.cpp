// question
// https://leetcode.com/problems/candy/description/

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}


int solve(vector<int>& ratings) {
        int n=ratings.size();
        if(n<2) return n;

        vector<int> res(n, 1);
        for(int i=1; i<n; i++)
            if(ratings[i]>ratings[i-1])
                res[i]=res[i-1]+1;

        for(int i=n-2; i>=0; i--)
            if(ratings[i]>ratings[i+1] and res[i]<=res[i+1])
                res[i]=res[i+1]+1;

        return std::accumulate(res.begin(), res.end(),0);
    }


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> ratings;
        read_int_vector(ratings);
        cout << "Case #" << i << ": ";
        cout << solve(ratings);
        cout << endl;
    }
}