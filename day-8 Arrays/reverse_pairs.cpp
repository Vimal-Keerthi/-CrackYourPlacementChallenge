/*

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 */

class Solution {
public:
    int mergeSort(int low, int high, vector<int>&nums) {
        if(low<high){
            int mid = (low+high)/2;
            int count = mergeSort(low, mid, nums)+mergeSort(mid+1, high, nums);
            int j = mid+1;
            for(int i=low;i<=mid;i++) {
                while(j<=high && nums[i]>nums[j]*2LL) j++;
                count += j - (mid+1);
            }
            sort(nums.begin()+low, nums.begin()+high+1);
            return count;
        }
        else return 0;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
    }
};
