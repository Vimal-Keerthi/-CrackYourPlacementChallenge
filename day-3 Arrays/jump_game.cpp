/*
Jump Game
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size() - 1;
        int min = length;
        for (int i = length; i >= 0; i--)
        {
            if (i + nums[i] >= min)
            {
                min = i;
            }
        }
        return min == 0;
    }
};
