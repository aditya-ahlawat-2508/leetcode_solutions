class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<char>>& board) {
        // out of bounds ya 'O' nahi → ruk jao
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;

        board[r][c] = '#';               // safe mark
        dfs(r-1, c, board);              // up
        dfs(r+1, c, board);              // down
        dfs(r, c-1, board);              // left
        dfs(r, c+1, board);              // right
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // Step 1: border ke 'O' se DFS
        for (int i = 0; i < m; i++) {
            if (board[i][0]   == 'O') dfs(i, 0,   board);   // left col
            if (board[i][n-1] == 'O') dfs(i, n-1, board);   // right col
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j]   == 'O') dfs(0, j,   board);   // top row
            if (board[m-1][j] == 'O') dfs(m-1, j, board);   // bottom row
        }

        // Step 2: full scan
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';   // surrounded → capture
                else if (board[i][j] == '#') board[i][j] = 'O'; // safe → restore
            }
        }
    }
};