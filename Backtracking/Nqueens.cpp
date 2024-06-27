    #include <iostream>
    #include <vector>

    using namespace std;

    // Function to print the board
    void printBoard(const vector<vector<int>>& board) {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }

    // Function to check if it's safe to place a queen at board[row][col]
    bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
        // Check this column on the upper side
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 1)
                return false;

        // Check the upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 1)
                return false;

        // Check the upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    // Recursive function to solve N-Queens problem
    bool solveNQueens(vector<vector<int>>& board, int row, int n) {
        if (row >= n) {
            printBoard(board); // Print the board when a solution is found
            return true;
        }

        bool res = false;
        for (int col = 0; col < n; ++col) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1; // Place the queen
                res = solveNQueens(board, row + 1, n) || res;
                board[row][col] = 0; // Backtrack and remove the queen
            }
        }
        return res;
    }

    int main() {
        int n;
        cout << "Enter the value of N: ";
        cin >> n;

        vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the board

        if (!solveNQueens(board, 0, n)) {
            cout << "No solution exists for N = " << n << endl;
        }

        return 0;
    }
