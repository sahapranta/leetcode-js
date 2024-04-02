/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) return false;
    let s1 = new Map();    

    for (let i = 0; i < s.length; i++) {
        if (s1.has(s[i])) {
            s1.set(s[i], s1.get(s[i]) + 1);
        } else {
            s1.set(s[i], 1);
        }

        if (s1.has(t[i])) {
            s1.set(t[i], s1.get(t[i]) - 1);
        } else {
            s1.set(t[i], -1);
        }
    }

    let result = true;

    s1.forEach(m => {
        if (m < 0) {
            result= false;
        }
    })

    return result;
};
