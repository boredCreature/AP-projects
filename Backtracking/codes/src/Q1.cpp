#include "Q1.hpp"
using namespace std;


//a funciton that finds obsticles in board implemented recursivly 
void findObstciles(vector<string> inputBoard, set<pair<int, int>>& obstaclePositions, int row) {
    if (row == SIZE) {
        return;
    }
    for (int col = 0; col < SIZE; col ++) {
        if (inputBoard[row][col] == '*') {
            obstaclePositions.insert({row, col});
        }
    }
    findObstciles(inputBoard, obstaclePositions, row + 1);
}

vector<string> getInput() {
    string lineOfInput;
    vector <string> inputBoard;
    while (getline(cin, lineOfInput) && !lineOfInput.empty()) {
        inputBoard.push_back(lineOfInput);
    }
    return inputBoard;
}

//a function to check whether queens can threat eachother or not
bool threat(int r1, int c1, int r2, int c2) {
    return ((r1 == r2) || (c1 == c2) || (abs(r1 - r2) == abs(c1 - c2)));
}

bool checkObstacle(int row, int col, set <pair<int, int>> obstaclePositions) {
    return obstaclePositions.count({row, col}) > 0;
}

bool isSafeToPutAt(int row, int col, int queenColInRow[] ,const set <pair<int, int>>& obstaclePositions) {
    if (checkObstacle(row, col, obstaclePositions)) 
            return false;
    for(int prevRow = 0; prevRow < row; prevRow ++) {
        if (threat(row, col, prevRow, queenColInRow[prevRow])) 
            return false;
    }
    return true;
}

void solveEightQueen(int row, int& solutionNumber, int queenColInRow[], const set <pair<int, int>>& obstaclePositions) {
    if (row == SIZE) {
        solutionNumber++;
        return;
    }

    for(int col = 0; col < SIZE; col ++) {
        if(isSafeToPutAt(row, col, queenColInRow, obstaclePositions)) {
            queenColInRow[row] = col;
            solveEightQueen(row + 1, solutionNumber, queenColInRow, obstaclePositions);
            queenColInRow[row] = -1;
        }
    }

}
void fillBoardWithNegOne(int queenColInRow[]) {
    for(int i = 0; i < SIZE; i++) {
        queenColInRow[i] = -1;
    }

}

