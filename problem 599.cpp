// Question link :- https://leetcode.com/problems/minimum-index-sum-of-two-lists/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m;
        for(int i=0;i<list1.size();i++)
            m[list1[i]] = i;
        int max_value = 9999;
        vector <string> res;
        for(int i=0;i<list2.size();i++)
        {
            if(m.find(list2[i])!=m.end())
            {
                int temp = i + m[list2[i]];
                if(temp<max_value)
                {
                    max_value = temp;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else if(temp == max_value)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};