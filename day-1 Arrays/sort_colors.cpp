/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

// Method 1: General method

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z,o,t;
        z=o=t=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) z++;
            else if(nums[i]==1) o++;
            else t++;
        }
        int i=0;
        while(z>0){
            nums[i]=0;
            z--;
            i++;
        }
        while(o>0){
            nums[i]=1;
            o--;
            i++;
        }
        while(t>0){
            nums[i]=2;
            t--; i++;
        }
    }
};

TC: O(n)

// Method 2: Three pointers

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

TC: O(n)
