/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function (nums) {
    const results = [];

    for (let i = 0; i < nums.length; i++) {
        let num = Math.abs(nums[i]);

        let prev = nums[num - 1];

        if (prev > 0) {
            nums[num - 1] = -prev;
        } else {
            results.push(num)
        }
    }

    return results;
};
