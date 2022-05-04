/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])){
            int tar=-nums[i];
            int l=i+1, h=nums.size()-1;
            while(l<h){
                if(nums[l]+nums[h]==tar){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[h]);
                    res.push_back(v);
                    while(l<h) {if(nums[l]==nums[l+1]) l++; else break;}
                    while(l<h) {if(nums[h]==nums[h-1]) h--; else break;}
                    l++;h--;
                }
                else if(nums[l]+nums[h]>tar) h--;
                else l++;
            }
            }
        }
        return res;
    }
};


