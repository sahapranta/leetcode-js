/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function (s) {
    let open = 0;
    let str = [];

    for (let i = 0; i < s.length; i++) {
        if (s[i] == '(') {
            open++;
        }

        if (s[i] == ')') {
            if (open <= 0) {
                continue;
            } else {
                open--;
            }
        }

        str.push(s[i]);
    }

    for (let i = str.length - 1; i >= 0; i--) {
        if (str[i] == '(' && open > 0) {
            str[i]='';
            open--;
        }
    }

    return str.join('');
};
