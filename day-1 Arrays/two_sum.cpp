/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int x,i;
        for(i=0;i<nums.size();i++){
            mp[i]=target-nums[i];
        }
        auto it = mp.begin();
        vector<int> v;
        while(it!=mp.end()){
            auto it1 = find(nums.begin(),nums.end(),it->second);
            int index = it1-nums.begin();
            if(it1!=nums.end()&& index!=it->first){
                v.push_back(it->first);
                v.push_back(index);
                break;
            }
            ++it;
        }
        return v;
    }
};
