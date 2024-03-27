/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function (nums, k) {
    if (k == 0) return 0;
    const n = nums.length;
    let i = 0, j = 0, result = 0, product = 1;

    while (j < n) {
        product *= nums[j];
        while (product >= k && i <= j) {
            product /= nums[i];
            i++;
        }
        result += (j - i) + 1;
        j++;
    }

    return result;
};
