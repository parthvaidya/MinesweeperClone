// // main.cpp
#include "minesweeper.h"

class MyMinesweeper : public Minesweeper {
public:
    MyMinesweeper(int size) : Minesweeper(size) {}

    void printBoard() override {
        Minesweeper::printBoard();
    }
};

int main() {
    std::cout << "WELCOME TO MINESWEEPER GAME" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "RULES:" << std::endl;
    std::cout << "1. The board is divided into cells, with mines randomly distributed." << std::endl;
    std::cout << "2. To win, you need to open all the cells." << std::endl;
    std::cout << "3. The number on a cell shows the number of mines adjacent to it." << std::endl;
    std::cout << "4. Interact, evolve and enjoy!" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "How to play" << std::endl;
    std::cout << "1. The user will give x and y coordinates." << std::endl;
    std::cout << "2. In each step check for win or lose." << std::endl;
    std::cout << " " << std::endl;
    int n;
    std::cout << "Enter the size of the board (n*n, where n >= 9): ";
    std::cin >> n;

    if (n < 9) {
        std::cout << "Invalid size. Size must be greater than or equal to 9!" << std::endl;
        return 1;
    }

    MyMinesweeper game(n);

    int x, y;
    bool gameOver = false;

    std::cout << "Enter the x and y coordinates: ";
    std::cin >> x >> y;

    if (!game.revealCell(x, y)) {
        std::cout << "You stepped on a mine. Game Over!" << std::endl;
        gameOver = true;
    }

    while (!gameOver) {
        game.printBoard();

        std::cout << "Enter the x and y coordinates: ";
        std::cin >> x >> y;

        if (!game.revealCell(x, y)) {
            std::cout << "You stepped on a mine. Game Over!" << std::endl;
            gameOver = true;
        }

        // Check if the player has won
        bool allRevealed = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!game.revealed[i][j] && game.board[i][j] != -1) {
                    allRevealed = false;
                    break;
                }
            }
            if (!allRevealed) {
                break;
            }
        }

        if (allRevealed) {
            std::cout << "Congratulations! You won the game." << std::endl;
            gameOver = true;
        }
    }

    return 0;
}
