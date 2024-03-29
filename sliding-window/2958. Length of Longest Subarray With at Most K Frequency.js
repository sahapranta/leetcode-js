/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubarrayLength = function (nums, k) {
    if (k == 0) return 0;
    const n = nums.length;
    const map = {};
    let i = 0, j = 0, result = 0;

    while (j < n) {
        if (map[nums[j]]) {
            map[nums[j]]++;
        } else {
            map[nums[j]] = 1;
        }

        while (i < j && map[nums[j]] > k) {
            map[nums[i]] -= 1;
            i++;
        }

        result = Math.max(result, j - i + 1);
        j++;
    }

    return result;
};
