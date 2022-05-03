/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        i=0;j=1;
        while(i!=j&&i<nums.size()&&j<nums.size()){
            if(nums[i]!=0) i++;
            if(nums[i]==0&&nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
};

TC: O(n)
