/*
Find all duplicates in an array
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i=0,j=0;
        while(j<nums.size()) {
            while(j<nums.size() && nums[i]==nums[j]) j++;
            if(j-i==2) res.push_back(nums[i]);
            i=j;
        }
        return res;
    }
};
