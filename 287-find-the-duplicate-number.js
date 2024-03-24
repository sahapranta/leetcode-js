/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function (nums) {
    // HashMap Choice
    // const seen = {};
    // for (let i = 0; i < nums.length; i++) {
    //     if (seen[nums[i]]) {
    //         return nums[i];
    //     } else {
    //         seen[nums[i]] = 1;
    //     }
    // }

    // Hare & Tortoise
    let slow = nums[0];
    let fast = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];

    // detect the cycle
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = nums[0];

    // ensure the starting point
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
};
