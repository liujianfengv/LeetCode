char hash_table[9];
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
    for (int col = 0; col < 9; ++col) {
        if (!checkDuplicate({board[0][col], board[1][col], board[2][col],
                             board[3][col], board[4][col], board[5][col],
                             board[6][col], board[7][col], board[8][col]})) {
            return false;
        }
    }

    for (int row = 0; row < 9; ++row) {
        if (!checkDuplicate({board[row][0], board[row][1], board[row][2],
                             board[row][3], board[row][4], board[row][5],
                             board[row][6], board[row][7], board[row][8]})) {
            return false;
        }
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int real_row = row * 3;
            int real_col = col * 3;
            if (!checkDuplicate({board[real_row][col * 3], board[real_row][col * 3 + 1], board[real_row][col * 3 + 2],
                                 board[real_row + 1][col * 3], board[real_row + 1][col * 3 + 1], board[real_row + 1][col * 3 + 2],
                                 board[real_row + 2][col * 3], board[real_row + 2][col * 3 + 1], board[real_row + 2][col * 3 + 2]})) {
            return false;
        }
        }
    }
    return true;
}
private:
    bool checkDuplicate(vector<char> vec) {
        memset(hash_table, 0, sizeof(hash_table));
        for (auto & c : vec) {
            if (c == '.') {
                continue;
            }
            if (hash_table[c - '1'] == 1) {
                return false;
            } else {
                hash_table[c - '1'] = 1;
            }
        }
        return true;
    }
};