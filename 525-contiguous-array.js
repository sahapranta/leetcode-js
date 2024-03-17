/**
 * @param {number[]} nums
 * @return {number}
 */
// https://leetcode.com/problems/contiguous-array/submissions/1206360878/
var findMaxLength = function (nums) {
    let sum = 0;
    const map = new Map();
    map.set(0, -1)


    let result = 0;

    for (let i = 0; i < nums.length; i++) {
        sum += nums[i] === 1 ? 1 : -1;

        if (map.has(sum)) {
            result = Math.max(result, i - map.get(sum));
        } else {
            map.set(sum, i);
        }
    }

    return result;
};
