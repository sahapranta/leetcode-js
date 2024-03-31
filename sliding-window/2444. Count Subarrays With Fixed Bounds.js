/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function (nums, minK, maxK) {
    let min = -1, max = -1, cp = -1, ans = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == minK) {
            min = i;
        }

        if (nums[i] == maxK) {
            max = i;
        }

        if (nums[i] > maxK || nums[i] < minK) {
            cp = i;
        }

        let m = Math.min(min, max);
        let temp = m - cp;
        ans += temp <= 0 ? 0 : temp;
    }

    return ans;
};
