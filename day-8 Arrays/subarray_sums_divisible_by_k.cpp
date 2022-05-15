/*

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            int rem = sum%k;
            if(rem<0) rem += k;
            if(mp[rem]!=0) {
                count+=mp[rem];
                mp[rem]++;
            }
            else mp[rem]=1;
        }
        return count;
    }
};
