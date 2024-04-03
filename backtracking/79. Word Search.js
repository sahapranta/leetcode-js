/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    let m = board.length;
    let n = board[0].length;

    if (m * n < word.length)
        return false;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === word[0] && find(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];

function find(board, i, j, word, idx) {
    if (idx >= word.length)
        return true;

    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] !== word[idx])
        return false;

    let temp = board[i][j];
    board[i][j] = '$';

    for (let dir of directions) {
        let i_ = i + dir[0];
        let j_ = j + dir[1];

        if (find(board, i_, j_, word, idx + 1))
            return true;
    }

    board[i][j] = temp;
    return false;
}
