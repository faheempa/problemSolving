// question
// https://leetcode.com/problems/search-insert-position/description/

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


int solve(vector<int>& nums, int target) {
        int low{0}, high=nums.size()-1, res;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[mid]==target)
                return mid;

            if(target < nums[mid])
            {
                if(target<nums[low]) 
                    res = low;
                high = mid-1;
            }
            else
            {
                if(target>nums[high]) 
                    res = high+1;
                low=mid+1;
            }
        }
        return res;
    }


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        int target;
        cin >> target;

        cout << "Case #" << i << ": ";
        cout << solve(nums, target);
        cout << endl;
    }
}