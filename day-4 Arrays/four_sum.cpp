/*
Four sum
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n;i++) {

            for(int j=i+1;j<n;j++){

                int left = j+1, right = n-1;
                int sum = target - nums[i]-nums[j];
                while(left<right) {
                    if(nums[left]+nums[right]<sum) left++;
                    else if(nums[left]+nums[right]>sum) right--;
                    else {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        res.push_back(v);
                        while(left<right && nums[left]==v[2]) left++;
                        while(left<right && nums[right]==v[3]) right--;
                   }
                }
                while(j<n-1 && nums[j]==nums[j+1]) j++;

            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;

        }
        return res;
    }
};
