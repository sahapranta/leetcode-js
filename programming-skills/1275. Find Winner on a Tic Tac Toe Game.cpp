class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = moves.size();
        vector<vector<char>> m(3, vector<char>(3, '0'));

        for (int i = 0; i < n; i++) {
            m[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 'x' : 'o';
        }

        if (m[0][0] == 'x' && m[1][1] == 'x' && m[2][2] == 'x') {
            return "A";
        }

        if (m[0][0] == 'o' && m[1][1] == 'o' && m[2][2] == 'o') {
            return "B";
        }

        if (m[0][2] == 'x' && m[1][1] == 'x' && m[2][0] == 'x') {
            return "A";
        }

        if (m[0][2] == 'o' && m[1][1] == 'o' && m[2][0] == 'o') {
            return "B";
        }

        // Check rows and columns
        for (int j = 0; j < 3; j++) {
            if (m[j][0] == 'x' && m[j][1] == 'x' && m[j][2] == 'x') {
                return "A";
            }

            if (m[j][0] == 'o' && m[j][1] == 'o' && m[j][2] == 'o') {
                return "B";
            }

            if (m[0][j] == 'x' && m[1][j] == 'x' && m[2][j] == 'x') {
                return "A";
            }

            if (m[0][j] == 'o' && m[1][j] == 'o' && m[2][j] == 'o') {
                return "B";
            }
        }

        return n == 9 ? "Draw" : "Pending";
    }
};
