/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysWithKDistinct = function (nums, k) {
    return sliding(nums, k) - sliding(nums, k - 1);
};

function sliding(nums, k) {
    const map = new Map();
    const n = nums.length;

    let i = 0, j = 0, count = 0;

    while (j < n) {
        if (map.has(nums[j])) {
            map.set(nums[j], map.get(nums[j]) + 1);
        } else {
            map.set(nums[j], 1);
        }

        while (map.size > k) {
            if (map.has(nums[i])) {
                map.set(nums[i], map.get(nums[i])-1);

                if (map.get(nums[i]) == 0) {
                    map.delete(nums[i]);
                }
            }
            i++;
        }

        count += (j - i + 1);
        j++;
    }

    return count;
}
