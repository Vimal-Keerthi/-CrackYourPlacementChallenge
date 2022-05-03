/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space. */


// Method 1: sorting the array

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //sort the array
        for(int i=1;i<nums.size();i++){
                //check if the adjacent elemnent is similar
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return -1;
    }
};

T.C: O(nlogn) S.C: O(1)


// Method 2: using frequency array

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>=2) return nums[i];
        }
        return -1;
    }
};

T.C : O(n) S.C: O(n)

//Method 3: using two pointer approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        fast = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

T.C: O(n) S.C: O(1)
