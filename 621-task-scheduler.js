/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function (tasks, n) {
    const map = new Map();
    let maxVal = 0;
    let maxValCount = 0;

    for (let i = 0; i < tasks.length; i++) {
        let tVal = map.has(tasks[i]) ? map.get(tasks[i]) + 1 : 1
        map.set(tasks[i], tVal);

        if (tVal > maxVal) {
            maxVal = tVal;
            maxValCount = 1;
        } else if (tVal === maxVal) {
            maxValCount++;
        }
    }

    return Math.max(tasks.length, (maxVal - 1) * (n + 1) + maxValCount);
};
