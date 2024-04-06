class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        bool increasing = false;
        bool decreasing = false;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                increasing = true;
            } else if (nums[i] > nums[i + 1]) {
                decreasing = true;
            }
        }

        if (increasing && decreasing)
            return false;

        return true;
    }
};
