// Question link :- https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findNumbers(int index, int target,vector<int>& array, vector<vector<int> >& res, vector<int>& r)
    {
        if (index == array.size())
        {
            if (target == 0)
                res.push_back(r);
            return;
        }

        // if the array element is picked 
        if (array[index] <= target)
        {
            r.push_back(array[index]);
            findNumbers(index, target - array[index], array, res, r);
            r.pop_back();
        }
        // if the array element is not picked 
        findNumbers(index + 1, target, array, res, r);
    }
    vector<vector<int>> combinationSum(vector<int>& array, int target)
    {
        vector<int> r;
        vector<vector<int> > res;
        findNumbers(0, target, array, res, r);
        return res;
    }
};