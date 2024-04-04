class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int right = 0;
        int left = 0;
        int n = nums.size();

        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            
            right++;
        }
    }
};
