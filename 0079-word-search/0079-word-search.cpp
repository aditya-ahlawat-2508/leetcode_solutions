class Solution
{
public:
    bool isValid(vector<vector<char>>& board, int row, int col, string &word, int i)
    {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || board[row][col] != word[i])
        {
            return false;
        }
        if (i == word.size() - 1)
        {
            return true;
        }

        char temp = board[row][col];
        board[row][col] = '#';  // mark visited

        bool down = isValid(board, row + 1, col, word, i + 1);
        bool up = isValid(board, row - 1, col, word, i + 1);
        bool right = isValid(board, row, col + 1, word, i + 1);
        bool left = isValid(board, row, col - 1, word, i + 1);

        board[row][col] = temp;  // undo
        return up || down || right || left;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                if (isValid(board, row, col, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};