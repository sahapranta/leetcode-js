/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number = function (num) {
    // simplest approach
    return num.toString().replace('6', '9');

    // bruteforce approcah
    let digits = num.toString().split('');

    for (let i = 0; i < digits.length; i++) {
        if (digits[i] < 9) {
            digits[i] = 9;
            return digits.join('');
        }
    }

    return num;
};
