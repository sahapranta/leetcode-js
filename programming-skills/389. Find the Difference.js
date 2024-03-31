/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
    // const map = new Map();

    // for (let i = 0; i < s.length; i++) {
    //     if (map.has(s[i])) {
    //         map.set(s[i], map.get(s[i]) + 1);
    //     } else {
    //         map.set(s[i], 1)
    //     }
    // }

    // for (let i = 0; i < t.length; i++) {
    //     if (map.has(t[i])) {
    //         map.set(t[i], map.get(t[i]) - 1);
    //     } else {
    //         map.set(t[i], -1)
    //     }

    //     if (map.get(t[i]) < 0) {
    //         return t[i];
    //     }
    // }

    // let sum = 0;    

    // for (let i = 0; i < t.length; i++) {
    //     sum += t.charCodeAt(i);
    // }

    // for (let i = 0; i < s.length; i++) {
    //     sum -= s.charCodeAt(i);
    // }

    // return String.fromCharCode(sum);
    
    // Using XOR
    let sum = 0;    

    for (let i = 0; i < t.length; i++) {
        sum ^= t.charCodeAt(i);
    }

    for (let i = 0; i < s.length; i++) {
        sum ^= s.charCodeAt(i);
    }

    return String.fromCharCode(sum);
};
