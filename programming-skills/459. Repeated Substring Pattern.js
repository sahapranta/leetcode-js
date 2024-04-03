/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function (s) {
    const n = s.length;
    for (let i = Math.floor(n / 2); i >= 1; i--) {
        if (n % i != 0) { continue; }
        
        let times = n / i;
        let pattern = s.substring(0, i);
        let newString = '';
        
        while (times--) {
            newString += pattern;
        }

        if (newString == s) {
            return true;
        }
    }

    return false;
};
