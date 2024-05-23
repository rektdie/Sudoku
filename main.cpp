#include <iostream>
#include <chrono>

static int board[9][9] = {
    {1, 0, 8, 5, 0, 0, 0, 0, 9},
    {0, 3, 0, 0, 7, 0, 0, 2, 0},
    {0, 0, 5, 0, 3, 0, 1, 0, 0},
    {5, 0, 0, 4, 0, 2, 0, 0, 3},
    {0, 8, 7, 0, 0, 0, 5, 4, 0},
    {2, 0, 0, 3, 0, 7, 0, 0, 8},
    {0, 0, 1, 0, 4, 0, 7, 0, 0},
    {0, 4, 0, 0, 6, 0, 0, 9, 0},
    {8, 0, 0, 0, 0, 1, 2, 0, 4}
};

static bool IsValidNumber(int y, int x, int n) {
    // Row
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == n) {
            return false;
        }
    }

    // Column
    for (int i = 0; i < 9; i++) {
        if (board[i][x] == n) {
            return false;
        }
    }

    // Block
    int startingY = y / 3;
    int startingX = x / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startingY * 3 + i][startingX * 3 + j] == n) {
                return false;
            }
        }
    }

    return true;
}

void PrintBoard() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            std::cout << board[y][x] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Solve() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] == 0) {
                for (int i = 1; i <= 9; i++) {
                    if (IsValidNumber(y, x, i)) {
                        board[y][x] = i;
                        Solve();
                        board[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    PrintBoard();
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    std::cout << ms.count() << " ms\n";

    return 0;
}