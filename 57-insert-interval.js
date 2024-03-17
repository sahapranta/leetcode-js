/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */

// https://leetcode.com/problems/insert-interval/submissions/1206492431
var insert = function (intervals, newInterval) {
    let i = 0;
    const n = intervals.length;
    let result = [];

    for (i; i < n; i++) {
        if (intervals[i][1] < newInterval[0]) {
            result.push(intervals[i]);
        } else if (intervals[i][0] > newInterval[1]) {
            break;
        } else {
            newInterval = [Math.min(newInterval[0], intervals[i][0]), Math.max(intervals[i][1], newInterval[1])]
        }
    }

    result.push(newInterval);

    if (i < n) {
        result = result.concat(intervals.slice(i, n));
    }

    return result;
};
