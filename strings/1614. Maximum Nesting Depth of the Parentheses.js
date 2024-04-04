/**
 * @param {string} s
 * @return {number}
 */
var maxDepth = function (s) {
    var count = 0;
    var open = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] == '(') {
            open++;
        }

        if (s[i] == ')') {
            if (open > count) {
                count = open;
            }
            open--;
        }
    }

    return count;
};
