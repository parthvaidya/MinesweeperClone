// minesweeper.h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Minesweeper {
public:
//initialze the variables
    int n;
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> revealed;
    Minesweeper(int size) : n(size) {
        srand(time(NULL));
        initializeBoard();
    }

  //function to initialize the board
    void initializeBoard() {
        board = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        revealed = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

        // Place mines randomly in the board
        int mineCount = n * n / 8;
        while (mineCount > 0) {
            int x = rand() % n;
            int y = rand() % n;
            if (board[x][y] != -1) {
                board[x][y] = -1;
                updateNeighbors(x, y);
                mineCount--;
            }
        }
    }

//update neighbours of the board
    void updateNeighbors(int x, int y) {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] != -1) {
                    board[nx][ny]++;
                }
            }
        }
    }

//reveal the cells
    bool revealCell(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return false;
        }

        if (revealed[x][y]) {
            return true;
        }

        revealed[x][y] = true;

        if (board[x][y] == -1) {
            return false;
        }

        if (board[x][y] == 0) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    revealCell(nx, ny);
                }
            }
        }

        return true;
    }

//print the board
    virtual void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!revealed[i][j]) {
                    std::cout << "[ ]";
                } else if (board[i][j] == -1) {
                    std::cout << "[M]";
                } else {
                    std::cout << "[" << board[i][j] << "]";
                }
            }
            std::cout << std::endl;
        }
    }
};