/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
    const s1 = {};
    const t1 = {};

    for (let i = 0; i < s.length; i++) {
        if ((s1[s[i]] && s1[s[i]] !== t[i]) || (t1[t[i]] && t1[t[i]] !== s[i])) {
            return false;
        }

        s1[s[i]] = t[i];
        t1[t[i]] = s[i];
    }

    return true;
};
