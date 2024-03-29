/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function (nums, k) {
    const maxElement = Math.max(...nums);
    const n = nums.length;

    let i = 0, j = 0, result = 0, countMax = 0;

    while (j < n) {
        if (nums[j] == maxElement) {
            countMax++;
        }
        while (countMax >= k) {
            result += n - j;

            if (nums[i] == maxElement) {
                countMax--;
            }
            i++;
        }
        j++;
    }

    return result;
};
